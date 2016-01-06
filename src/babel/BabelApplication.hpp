#pragma once


// Awesomium
#include <Awesomium/WebCore.h>

// Core includes
#include "core/Application.hpp"

// GUI includes
#include "gui/Device.hpp"


namespace babel {


/// The babel driving application - sets up babel objects, device, and all subsystems
class BabelApplication
    : public core::Application
{
public:
	/// Constructor
                BabelApplication    ( const core::Config& config );
	/// Deconstructor
    virtual     ~BabelApplication   ( void );


	/// Attached to OnUpdate
    bool        update              ( core::Event& event );

private:
	/// The device (window)
	gui::Device::Handle	_device;
};

} // namespace babel
