#pragma once

// External libs
#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>

namespace gui {

/// Child class of Awesomium::Surface, for copying window to GL context
class GUISurface
	: public Awesomium::Surface
{
public:
	/// Constructor
					GUISurface (
						SDL_Window* window,
						Awesomium::WebView* view,
						int width,
						int height
					);
	/// Destructor
	virtual			~GUISurface	( void );

public:
	virtual void	Paint	(
						unsigned char *src_buffer,
						int src_row_span,
						const Awesomium::Rect &src_rect,
						const Awesomium::Rect &dest_rect
					);

	virtual void 	Scroll (
						int dx,
						int dy,
						const Awesomium::Rect &clip_rect
					);

private:
	SDL_Window*		_window;

}; // class GUISurface


} // namespace gui
