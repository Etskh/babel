
// External libraries
#include <SDL2/SDL_version.h>

// Utils
#include "util/safeDelete.hpp"

// Header
#include "BabelApplication.hpp"


using namespace babel;



BabelApplication::BabelApplication( const core::Config& config )
    : Application	( config )
	, _device		()
{
	//_webcore = Awesomium::WebCore::Initialize(Awesomium::WebConfig());
	printf(" --- Babel Code init ---\n");
	//printf("Log: Awesomium webcore %s initialised\n", _webcore->version_string() );

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

	// Create the device
	//config["width"] = "100";
	//config["height"]= "100";
	//config["title"] = "Babel Coder";
	_device = gui::Device::create(config);

	printf(" -- end -- \n");
}





BabelApplication::~BabelApplication (void)
{
	util::safeDelete(_device);

	// Shut down systems
	SDL_Quit();
}





void	BabelApplication::OnUpdate	( void )
{
	SDL_Event e;

	_device->update();

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

	//exit(0);
}
