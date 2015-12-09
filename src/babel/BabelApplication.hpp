#pragma once


// Awesomium
#include <Awesomium/WebCore.h>

// Core includes
#include "core/Application.hpp"

// GUI includes
#include "gui/Device.hpp"


namespace babel {

class BabelApplication
    : public core::Application
{
public:
                BabelApplication    ( const core::Config& config );
    virtual     ~BabelApplication   ( void );


    bool        update              ( Event& event );

private:
	gui::Device::Handle	_device;
};

} // namespace babel
