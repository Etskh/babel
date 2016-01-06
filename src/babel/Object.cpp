/*

*/

#include <cstring>

#include "duktape-1.3.1/include/duktape.h"

#include "Object.hpp"

using namespace babel;

Object::Handle	Object::create	( const core::String name )
{
	Object::Handle obj = Object::Handle(new Object(name));
	obj->_self = obj;
	return obj;
}


int						Object::run			( const core::Array& )
{
	printf("Running object %s\n", this->getName() );
	if( _rawCode ) {
		printf("Interpretting `%s`: %s\n", _rawCode->getLang(), _rawCode->getText() );
		if ( strcmp(_rawCode->getLang(),"javascript") == 0 ) {
			duk_context *ctx = duk_create_heap_default();
			if (ctx) {
				duk_eval_string(ctx, _rawCode->getText() );
				duk_destroy_heap(ctx);
			}
		} else {
			printf("Unknown language `%s`\n", _rawCode->getLang() );
		}
	}
	return 0;
}


void					Object::addChild	( const Object::Handle child )
{
	_children.push_back(child);
	child->_parent = _self;
}

void					Object::setRawCode	( RawCode::Handle rawCode )
{
	_rawCode = rawCode;
}


const Object::Handle	Object::getParent	( void ) const
{
	return _parent;
}

const char*				Object::getName		( void ) const
{
	return _name.c_str();
}


bool 		   Object::describe ( core::Serializer& serializer )
{
	serializer.begin("Object", babel::&Object, this );
	{
		serializer.addString("name", &_name );
		serializer.begin("meta");
		{
			serializer.addString("version", &meta.version_hash );
		}
		serializer.end();
	}
	serializer.end();

	return true;
}


Object::Object	( const core::String& name )
	: _name(name)
	, _desc("")
{
	// empty
}
