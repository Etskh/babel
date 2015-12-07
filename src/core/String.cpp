#include "String.hpp"

using namespace core;

String::String( const char* str )
{
	_str = str;
}
const char* String::c_str(void) const
{
	return _str.c_str();
}

String&		String::operator=	( const char* str )
{
	_str = str;
	return *this;
}

String&		String::operator=	( const String& str )
{
	_str = str._str;
	return *this;
}
