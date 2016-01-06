#ifndef BABEL_INCLUDED_BUFFER_HPP
#define BABEL_INCLUDED_BUFFER_HPP

#include <cstdlib>

namespace core {

/// Interface for all buffer objects - allows them to write and read
class Buffer
{
public:
	/// Write a null-terminated c-string to the buffer - bool means it failed
	virtual bool		writeString	( const char* str ) = 0;

	/// This copies the contents of the buffer into a byte array - bool means it failed
	virtual bool		get			( char* buffer, size_t nsize ) const = 0;

}; // class Buffer


} // namespace core

#endif // BABEL_INCLUDED_BUFFER_HPP
