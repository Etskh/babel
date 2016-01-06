#pragma once

// STL
#include <memory>

// External libs
#include <SDL2/SDL.h>
#include <Awesomium/WebCore.h>

// Core includes
#include "core/Config.hpp"
#include "core/Event.hpp"
#include "core/Application.hpp"

// GUI includes
#include "gui/GUISurfaceFactory.hpp"

namespace gui {


/// Main GUI object, used to show every other object
class Device
{
public:
	/// Handle used to reference a device
	typedef std::shared_ptr<Device>	Handle;


	/// Main creation method. Needs an application pointer for events
	static Device::Handle	create		( core::Application* app, const core::Config& config );
	/// Method called to unload the device - can be safely called more than once
	bool					destroy		( void );


	/// Attached to OnUpdate
	bool					update		( core::Event& event );
	/// Loads a GUI package, and calls it `name`
	void					loadGUI		( const char* name, const char* dirPath );

	/// Creates a page of content based on the data given
	bool					loadContent	( const char* content );

	/// Constructor
							Device		( core::Application* app, SDL_Window* window, int width, int height );
	/// Destructor
	virtual					~Device		( void );

private:
	/// Pointer to the application - later move to base object
	core::Application*      _app;
	/// Surface factory for instantiating a writable surface in SDL
	gui::GUISurfaceFactory	_sufaceFactory;
	/// The SDL window
	SDL_Window*				_window;
	/// The Awesomium web core
	Awesomium::WebCore*		_webcore;
	/// The current view (screen)
	Awesomium::WebView*		_view;
};


} // namespace gui
