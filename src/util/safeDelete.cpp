

#include "safeDelete.hpp"


namespace util {


/*
 * These specializations serve to free the passed argument and also provide the
 * base cases for the recursive call above, eg. when args is only a single item
 * one of the specializations below will be called by
 * safeDeleteSDL(std::forward<Args>(args)...), ending the recursion
 * We also make it safe to pass nullptrs to handle situations where we
 * don't want to bother finding out which values failed to load (and thus are null)
 * but rather just want to clean everything up and let cleanup sort it out
 */
template<>
void safeDelete<SDL_Window*>(SDL_Window*& win){
	if (!win){
		return;
	}
	SDL_DestroyWindow(win);
	win = nullptr;
}
template<>
void safeDelete<SDL_Renderer*>(SDL_Renderer*& ren){
	if (!ren){
		return;
	}
	SDL_DestroyRenderer(ren);
	ren = nullptr;
}
template<>
void safeDelete<SDL_Texture*>(SDL_Texture*& tex){
	if (!tex){
		return;
	}
	SDL_DestroyTexture(tex);
	tex = nullptr;
}
template<>
void safeDelete<SDL_Surface*>(SDL_Surface*& surf){
	if (!surf){
		return;
	}
	SDL_FreeSurface(surf);
	surf = nullptr;
}





template<>
void safeDelete<Awesomium::WebView*>(Awesomium::WebView*& view){
	if (!view){
		return;
	}
	view->Destroy();
	view = nullptr;
}



template<>
void safeDelete<gui::Device::Handle>(gui::Device::Handle& device){
	if (!device){
		return;
	}
	device->destroy();
}



} // namespace util
