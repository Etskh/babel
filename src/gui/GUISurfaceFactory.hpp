#pragma once

// External libs
#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>

namespace gui {

class GUISurfaceFactory
	: public Awesomium::SurfaceFactory
{
public:
				GUISurfaceFactory	( SDL_Window* window );
	virtual		~GUISurfaceFactory	( void );

public:
	virtual Awesomium::Surface*	CreateSurface (
									Awesomium::WebView*	view,
									int width,
									int height
								);

	virtual void				DestroySurface (
									Awesomium::Surface* surface
								);

private:
	SDL_Window*	_window;
	
}; // class GUISurfaceFactory


} // namespace gui
