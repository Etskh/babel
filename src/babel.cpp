/*

*/
// Awesomium
#include <Awesomium/WebCore.h>

// Core
//using namespace core;

// Babel
#include "babel/BabelApplication.hpp"
#include "babel/Object.hpp"
using namespace babel;

// Entry
int main(int argc, char* argv[]) {

	// Create the one application
	BabelApplication app(argc,argv);

	// Create the base objects
	// TODO(Etskh): bring these in from the web
	Object::Handle babelCore = Object::create(core::String("Core"));
	Object::Handle babelString = Object::create(core::String("String"));
	Object::Handle babelStringIndexOf = Object::create(core::String("indexOf"));
	RawCode::Handle babelStringIndexOfCode = RawCode::Handle(new RawCode());
	babelStringIndexOfCode->setText("return 0;");
	babelStringIndexOf->setRawCode(babelStringIndexOfCode);
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

	return app.exec();
}
