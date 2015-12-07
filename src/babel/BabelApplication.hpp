#pragma once

// Awesomium
#include <Awesomium/WebCore.h>

// Core includes
#include "core/Application.hpp"


namespace babel {

class BabelApplication
    : public core::Application
{
public:
                BabelApplication    ( int argc, char** argv );
    virtual     ~BabelApplication   ( void );

public:
    void		OnUpdate			( void );

private:
    Awesomium::WebCore* _webcore;
    Awesomium::WebView* _view;
};

} // namespace babel
