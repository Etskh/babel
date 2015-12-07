#include "BabelApplication.hpp"


#include <Awesomium/STLHelpers.h>


using namespace babel;

BabelApplication::BabelApplication( int argc, char** argv )
    : Application( argc, argv )
{
    _webcore = Awesomium::WebCore::Initialize(Awesomium::WebConfig());
	_view = _webcore->CreateWebView(500, 500, 0, Awesomium::kWebViewType_Window);

    Awesomium::WebURL url(Awesomium::WSLit("data:text/html,<h1>Hello World</h1>"));
    _view->LoadURL(url);
}

BabelApplication::~BabelApplication (void)
{
    _view->Destroy();
	Awesomium::WebCore::Shutdown();
}

void	BabelApplication::OnUpdate	( void )
{
    
}
