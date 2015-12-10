
// STL
#include <fstream>

// External libs
#include <Awesomium/STLHelpers.h>

// Util includes
#include "util/safeDelete.hpp"

// Header include
#include "Device.hpp"

using namespace gui;

Device::Handle		Device::create	( core::Application* app, const core::Config& )
{
	int width, height;
	SDL_Window* window(nullptr);

	//if( ! config["width"].to<int>( &width )) {
	//}
	
	
	width = 200;
	height = 100;

	window = SDL_CreateWindow(
		"Babel Code", //config["title"].c_str(),
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
	);
	if( window == nullptr ) {
		printf("Error: %s\n", SDL_GetError() );
		return Device::Handle();
	}
	else {
		// Finally 
		Device::Handle device( new Device( app, window, width, height) );

		// Check that the view was created properly
		if( device->_view == nullptr ) {
			printf("Error: %s\n", "Could not create WebView.");
			return Device::Handle();
		}

		// Load in the first page
		std::ifstream ifs("../data/babel.html");
		std::string contents( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()) );
		//printf(contents.c_str());
		Awesomium::WebURL url(Awesomium::WSLit((std::string("data:text/html,") + contents).c_str()));
		device->_view->LoadURL(url);

		return device;
	}
	return Device::Handle();
}

bool				Device::destroy	( void )
{
	util::safeDelete(_view);
	util::safeDelete(_window);

	return true;
}

bool				Device::update	( core::Event& )
{
	_webcore->Update();

	return true;
}


Device::Device			( core::Application* app, SDL_Window* window, int width, int height )
	: _app ( app )
	, _sufaceFactory( window )
	, _window   ( window )
	, _webcore	( nullptr )
	, _view		( nullptr )
{
	_webcore = Awesomium::WebCore::Initialize(Awesomium::WebConfig());
	if( _webcore == nullptr) {
		printf("Error: %s\n", "Could not create Webcore.");
		return;
	}
	printf("Log: Awesomium webcore %s initialised\n", _webcore->version_string() );
	_webcore->set_surface_factory( &_sufaceFactory );

	// Finally, create the GUI interface
	_view = _webcore->CreateWebView( width, height, 0, Awesomium::kWebViewType_Offscreen );


	// Register for the OnUpdate event
	app->OnUpdate += CALLBACK( &Device::update );
	//app->OnUpdate += std::bind( &Device::update, this, std::placeholders::_1 );
}


Device::~Device			( void )
{
	destroy();
	Awesomium::WebCore::Shutdown();
}
