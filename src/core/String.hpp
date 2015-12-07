/*


*/
#pragma once

#include <string>


namespace core {

/// Wrapper around base string class
class String {
public:
	/// Constructor
	explicit		String		( const char* str );
	/// std::string-style c_str()
	const char*		c_str		( void )			const;
	/// Assignment from a null-terminated string
	String&			operator=	( const char* str );
	/// Assignment from another String
	String&			operator=	( const String& str );

private:
	/// The string itself
	std::string	_str;
};

} // namespace core
