/*


*/
#pragma once

#include <string>


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


template<>	bool	String::to		( int& out ) const;
//template<>	bool	String::from	( const int& in );

} // namespace core
