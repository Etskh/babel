#pragma once

// External libs
#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>

namespace gui {

/// Attached to the Awesomium::WebCore to create a GUISurface
class GUISurfaceFactory
	: public Awesomium::SurfaceFactory
{
public:
	/// Constructor
				GUISurfaceFactory	( SDL_Window* window );
	/// Destructor
	virtual		~GUISurfaceFactory	( void );

public:
	/// Creates a GUISurface object - inherited from Awesomium::SurfaceFactory
	virtual Awesomium::Surface*	CreateSurface (
									Awesomium::WebView*	view,
									int width,
									int height
								);

	/// Destroys the GUISurface - inherited from Awesomium::SurfaceFactory
	virtual void				DestroySurface (
									Awesomium::Surface* surface
								);

private:
	/// Pointer to the SDL window
	SDL_Window*	_window;

}; // class GUISurfaceFactory


} // namespace gui
