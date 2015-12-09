/*
	from http://www.willusher.io/sdl2%20tutorials/2014/08/01/postscript-1-easy-cleanup/

	renamed "cleanup" to "safeDelete"
*/
#pragma once

// STL
#include <utility>

// Extern libs
#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>

// GUI includes
#include "gui/Device.hpp"

namespace util {

/*
 * Recurse through the list of arguments to clean up, cleaning up
 * the first one in the list each iteration.
 */
template<typename T, typename... Args>
void safeDelete(T& t, Args&&... args) {

	//Cleanup the first item in the list
	safeDelete(t);
	//Recurse to clean up the remaining arguments
	safeDelete(std::forward<Args>(args)...);
}

template<> void safeDelete<SDL_Window*>		( SDL_Window*& win );
template<> void safeDelete<SDL_Renderer*>	( SDL_Renderer*& ren );
template<> void safeDelete<SDL_Texture*>	( SDL_Texture*& tex );
template<> void safeDelete<SDL_Surface*>	( SDL_Surface*& surf );

template<> void safeDelete<Awesomium::WebView*>( Awesomium::WebView*& view );

template<> void safeDelete<gui::Device::Handle>( gui::Device::Handle& device );

} // namespace util
