
// Header include
#include "gui/GUISurfaceFactory.hpp"

// GUI includes
#include "gui/GUISurface.hpp"


using namespace gui;


GUISurfaceFactory::GUISurfaceFactory	( SDL_Window* window )
    : Awesomium::SurfaceFactory ()
    , _window ( window )
{
	// empty
}

GUISurfaceFactory::~GUISurfaceFactory	( void )
{
	// empty
}


Awesomium::Surface*	GUISurfaceFactory::CreateSurface (
		Awesomium::WebView*	view,
		int width,
		int height
	)
{
	return new GUISurface(_window, view, width, height);
}

void		GUISurfaceFactory::DestroySurface (
		Awesomium::Surface* surface
	)
{
	delete surface;
}
