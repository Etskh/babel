
// STL
#include <cstdlib>
#include <cassert>

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



String&		String::replace		( const char* subject, const char* replacement )
{
	// Sanitize
	assert( subject != nullptr );
	assert( replacement != nullptr );

	// Do the thing
	replace(subject, replacement, this);

	// Return it
	return *this;
}



bool		String::replace		( const char* subject, const char* replacement, OUT String* out) const
{
	// Sanitize
	assert( subject != nullptr );
	assert( replacement != nullptr );
	assert( out != nullptr );

	// If it can't find it, then return false
	size_t pos = _str.find(subject);
	if( pos == std::string::npos ) {
		return false;
	}

	// Do the thing
	out->_str = _str;
	out->_str.replace( pos, strlen(subject), replacement );

	// We did the thing. Youppie!
	return true;
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
