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

public:
    void		OnUpdate			( void );

private:
	gui::Device::Handle	_device;
};

} // namespace babel
