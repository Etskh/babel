/*

*/
// Core Includes
#include "core/Config.hpp"
#include "core/MemoryBuffer.hpp"

// Util includes
#include "util/JSONSerializer.hpp"

// Babel
#include "babel/BabelApplication.hpp"
#include "babel/Object.hpp"
using namespace babel;

// Entry
int main(int argc, char* argv[]) {

	// Create the one application
	core::Config config(argc,argv);
	BabelApplication app(config);
	const unsigned int BUFFER_SIZE = 1024;
	char buf[BUFFER_SIZE];
	core::MemoryBuffer buffer(BUFFER_SIZE);
	util::JSONSerializer json(buffer);


	// Create the base objects
	///TODO bring these in from the web
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

	babelCore->serialize(json);

	buffer.get( buf, BUFFER_SIZE);
	printf("%s\n", buf );

	// ... when the user hits "build & run"
	// Run the code
	//core::Array args;
	//entry->run(args);

	return app.exec();
}
