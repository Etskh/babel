#ifndef BABEL_INCLUDED_JOSNSERIALIZER_HPP
#define BABEL_INCLUDED_JOSNSERIALIZER_HPP



// STL includes
#include <cstdlib>
#include <string>

// Core includes
#include "core/Serializer.hpp"

namespace util {

class JSONSerializer
	: public core::Serializer
{
public:
	/// Constructor that takes a buffer reference
				JSONSerializer	( core::Buffer& buffer );

	/// Destructor
	virtual		~JSONSerializer	( void );

	/// Starts an object
	void		begin			( const char* objectType );

	/// Ends an object
	void		end				( void );

	/// Adds a string field to the current object
	void		addString		( const char* name, const char* value );

	/// Begins a readable object
	void		begin			( const char* objectType ) const;

	/// Ends a readable object
	void		end				( void ) const;

	/// Gets a string
	void		getString		( const char* name, OUT core::String* field ) const ;


private:

	/// Indents one section in
	void		indent			( void );

	/// Unindents by one section
	void		unindent		( void );

	/// Gets the indentation string
	const char*	getIndent		( void );

private:

	/// How many indents there are currently
	mutable size_t		_indentIndex;

	/// The string that represents the actual indent
	mutable std::string _indent;

	/// The character used to indent
	char				_indentCharacter;

	/// How many indent characters per indent
	size_t				_indentCount;


}; // class JSONSerializer


} // namespace util



#endif // BABEL_INCLUDED_JOSNSERIALIZER_HPP
