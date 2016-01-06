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

	/**
	 * Paints the window Inherited from Awesomium::Surface
	 *
	 * @param src_buffer the data of the source buffer, formatted as ABGR
	 * @param src_row_span the byte-size of each row
	 * @param src_rect The source rectangle
	 * @param dest_rect The destination rectangle
	 * 
	 */
	virtual void	Paint	(
						unsigned char*	src_buffer,
						int				src_row_span,
						const			Awesomium::Rect& src_rect,
						const			Awesomium::Rect& dest_rect
					);

	/// Calls a redraw the window Inherited from Awesomium::Surface
	virtual void 	Scroll (
						int		dx,
						int		dy,
						const	Awesomium::Rect &clip_rect
					);

private:
	/// Pointer to SDL window
	SDL_Window*		_window;

}; // class GUISurface


} // namespace gui
