#ifndef BABEL_INCLUDED_MEMORYBUFFER_HPP
#define BABEL_INCLUDED_MEMORYBUFFER_HPP


// STL includes
#include <cstdlib>
#include <cstring>

// Core includes
#include "Buffer.hpp"


namespace core {

/// Memory
class MemoryBuffer
	: public Buffer
{
public:
	/// Constructor - takes a size in bytes
						MemoryBuffer	( size_t memSize );

	/// Destructor
	virtual				~MemoryBuffer	( void );

	/// Write a null-terminated c-string to the buffer - bool means it failed
	virtual bool		writeString		( const char* str );

	/// This copies the contents of the buffer into a byte array - bool means it failed
	virtual bool		get				( char* buffer, size_t nsize ) const;

	/// Returns the size of the buffer in bytes
	size_t				getSize			( void ) const;

private:
	/// Size of the buffer in bytes
	size_t		_memSize;
	/// The memory buffer
	char*		_buffer;
	/// The cursor to the place in memory to write into
	char* 		_cursor;


}; // class MemoryBuffer

} // namespace core


#endif // BABEL_INCLUDED_MEMORYBUFFER_HPP
