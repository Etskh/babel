
// STL
#include <cstdlib>


#include "String.hpp"


using namespace core;

String::String( void )
	: _str("")
{
	// empty
}

String::String( const char* str )
	: _str(str)
{
	// empty
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


template<>	bool	String::to	( int& out ) const
{
	out = atoi(_str.c_str());
	return true;
}
/*
template<>	bool	String::from( const int& in ) const
{
	try {
		int notByRef = in;
		_str = std::to_string(notByRef);
	}
	catch(std::exception& e) {
		return false;
	}
	return true;
}
*/
