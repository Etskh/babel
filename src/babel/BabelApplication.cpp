

// External libraries
#include <SDL2/SDL_version.h>

// STL includes
#include <fstream>

// Core includes
#include "core/Event.hpp"

// Util includes
#include "util/safeDelete.hpp"

// Header
#include "BabelApplication.hpp"


using namespace babel;



BabelApplication::BabelApplication( const core::Config& config )
    : Application	( config )
	, _device		( nullptr )
{
	printf(" --- Babel Code init ---\n");

    if( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		printf("SDL Init failed: %s\n", SDL_GetError() );
		return;
	}
	SDL_version compiled;
	SDL_VERSION(&compiled);
	printf(
		"Log: SDL version %d.%d.%d initialised\n",
		compiled.major, compiled.minor, compiled.patch
	);

	// Add event listeners to the application
	OnUpdate += CALLBACK( &BabelApplication::update );

	// Create the device
	//config["width"] = "100";
	//config["height"]= "100";
	//config["title"] = "Babel Coder";
	_device = gui::Device::create( this, config);

	// Load in file from data folder
	//
	std::ifstream ifs("../data/babel.html");
	std::string contents( (std::istreambuf_iterator<char>(ifs) ),
				   (std::istreambuf_iterator<char>()) );
	//
	// Replace the templates with our data
	//
	{
		core::String contentStr(contents.c_str());
		contentStr.replace("{{name}}","Core");
		contentStr.replace("{{children}}","Childsss");

		// Load the contents of the file into the device
		//
		_device->loadContent(contentStr.c_str());
	}

	printf(" -- end -- \n");
}





BabelApplication::~BabelApplication (void)
{
	util::safeDelete(_device);

	// Shut down systems
	SDL_Quit();
}





bool	BabelApplication::update	( core::Event& )
{
	SDL_Event e;
	while (SDL_PollEvent(&e)){
		if (e.type == SDL_QUIT){
			exit(0);
		}
		if (e.type == SDL_KEYDOWN){
			exit(1);
		}
		if (e.type == SDL_MOUSEBUTTONDOWN){
			exit(2);
		}
	}

	return true;
}
