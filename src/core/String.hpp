/*


*/
#pragma once

// STL includes
#include <string>

// Core includes
#include "Types.hpp"


namespace core {

/// Wrapper around base string class
class String {
public:
	/// Constructor
					String		( void );
	/// Constructor
					String		( const char* str );
	/// std::string-style c_str()
	const char*		c_str		( void )			const;
	/// Assignment from a null-terminated string
	String&			operator=	( const char* str );
	/// Assignment from another String
	String&			operator=	( const String& str );


	/// Replace - like the PHP version, returns *this
	String&			replace		( const char* subject, const char* replacement );
	/// Replace - like the PHP version, but const
	bool			replace		( const char* subject, const char* replacement, OUT String* out) const;



	/// Make it into otherstuff
	template <typename T>
	bool			to			( T& out ) const;


	/// Make other stuff into string
	//template <typename T>
	//bool			from		( const T& in );

private:
	/// The string itself
	std::string	_str;
};



/// Make it into otherstuff
template <typename T>
bool	String::to	( T& ) const
{
	return false;
}
/*template <typename T>
bool	String::from( const T& )
{
	return false;
}*/

/**
 * @param out the value to assign the integer to
 * @returns true on success, false on failure
 */
template<>	bool	String::to		( int& out ) const;
//template<>	bool	String::from	( const int& in );

} // namespace core
