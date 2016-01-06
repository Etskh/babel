#ifndef BABEL_INCLUDED_SERIALIZER_HPP
#define BABEL_INCLUDED_SERIALIZER_HPP

// STL includes
#include <string>

// Core includes
#include "Buffer.hpp"
#include "String.hpp"
#include "Types.hpp"


namespace core {

/// Base class to serialize objects
class Serializer
{
public:
	/// Constructor - takes a buffer, any buffer
					Serializer		( Buffer& buffer );
	/// Destructor
	virtual			~Serializer		( void );


	/// Returns the buffer pointer associated with this serializer
	Buffer*			buffer			( void );


	template<class T>
	void			begin			( const char* objectName, T* t );

	/// Starts an 'object'
	virtual	void	begin			( const char* objectType ) = 0;

	/// Ends an 'object'
	virtual void	end				( void ) = 0;

	/// Add a string inside the object
	virtual void	addString		( const char* name, core::String* field ) = 0;


protected:
	/// A reference to the buffer
	Buffer&		_buffer;

}; // class Serializer

} // namespace core

#endif // BABEL_INCLUDED_SERIALIZER_HPP
