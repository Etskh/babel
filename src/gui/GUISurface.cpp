
// STL
#include <cstdio>


// Header includes
#include "GUISurface.hpp"

using namespace gui;



GUISurface::GUISurface (
			SDL_Window* window,
			Awesomium::WebView*,
			int,
			int
		)
    : Awesomium::Surface()
	, _window ( window )
{
	// empty
}


GUISurface::~GUISurface	( void )
{
	// empty
}

void	GUISurface::Paint	(
			unsigned char *src_buffer,
			int src_row_span,
			const Awesomium::Rect& src_rect,
			const Awesomium::Rect& /*dest_rect*/
		)
{
	/// TODO(Etskh): Draw only what you need to draw
    SDL_Surface* screen = SDL_GetWindowSurface(_window);
	SDL_Surface* websurface = SDL_CreateRGBSurfaceFrom(
		src_buffer,
		src_rect.width,
		src_rect.height,
		32,
		src_row_span,
		0x000000ff,
		0x0000ff00,
		0x00ff0000,
		0xff000000
	);

    SDL_BlitSurface(websurface, NULL, screen, NULL);
	SDL_UpdateWindowSurface(_window);

	printf("painting...\n");
}

void 	GUISurface::Scroll (
			int /*dx*/,
			int /*dy*/,
			const Awesomium::Rect& /*clip_rect*/
		)
{
	// empty
}
