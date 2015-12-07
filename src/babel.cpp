/*

*/
#include <Awesomium/WebCore.h>


// Core
#include "core/Application.hpp"
using namespace core;

// Babel
#include "babel/Object.hpp"
using namespace babel;

// Entry
int main(int argc, char* argv[]) {

	Application app(argc,argv);

	// Create the base objects
	// TODO(Etskh): bring these in from the web
	Object::Handle babelCore = Object::create(core::String("Core"));
	Object::Handle babelString = Object::create(core::String("String"));
	Object::Handle babelStringIndexOf = Object::create(core::String("indexOf"));
	RawCode::Handle babelStringIndexOfCode = RawCode::Handle(new RawCode());
	babelStringIndexOfCode->setText("return 0;");
	babelStringIndexOf->setRawCode(babelStringReverseCode);
	babelString->addChild(babelStringIndexOf);
	babelCore->addChild(babelString);

	// Create the start project
	Object::Handle entry = Object::create(core::String("MyEntry"));
	RawCode::Handle code = RawCode::Handle(new RawCode());
	code->setText("print(\"Works.\")");
	code->setLang("javascript");
	entry->setRawCode( code );


	// ... when the user hits "build & run"
	// Run the code
	core::Array args;
	entry->run(args);


	// Boot up Awesomium for interface & URL stuff
	//
	Awesomium::WebCore* web_core = Awesomium::WebCore::Initialize(Awesomium::WebConfig());
	Awesomium::WebView* view = web_core->CreateWebView(500, 500, 0, Awesomium::kWebViewType_Window);
	view->Destroy();

	Awesomium::WebCore::Shutdown();
	return app.exec();
}
