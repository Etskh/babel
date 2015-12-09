#pragma once

// STL
#include <memory>

// External libs
#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>

// Core includes
#include "core/Config.hpp"

// GUI includes
#include "gui/GUISurfaceFactory.hpp"

namespace gui {

class Device
{
public:
	typedef std::shared_ptr<Device>	Handle;
public:
	static Device::Handle	create		( const core::Config& config );
	bool					destroy		( void );

public:
	void					update		( void );

public:
							Device		( SDL_Window* window, int width, int height );
	virtual					~Device		( void );

private:
	gui::GUISurfaceFactory	_sufaceFactory;
	SDL_Window*				_window;
	Awesomium::WebCore*		_webcore;
	Awesomium::WebView*		_view;
};


} // namespace gui
