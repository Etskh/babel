
// STL includes
#include <cassert>


// Core includes
#include "Types.hpp"
#include "MemoryBuffer.hpp"

using namespace core;



MemoryBuffer::MemoryBuffer	( size_t memSize )
	: Buffer ()
	, _memSize (memSize)
	, _buffer ( nullptr )
	, _cursor ( nullptr )
{
	_buffer = new char[ _memSize ];
	_cursor = _buffer;

	memset( _buffer, 0, memSize );
}



MemoryBuffer::~MemoryBuffer	( void )
{
	delete[] _buffer;
}



bool	MemoryBuffer::writeString		( const char* str )
{
	assert( str != nullptr );

	size_t len = strlen(str);
	size_t remaining = _memSize - (reinterpret_cast<size_t>(_cursor) - reinterpret_cast<size_t>(_buffer));

	assert( len <= remaining );

	memcpy( _cursor, str, len+1 );
	_cursor += len;

	return true;
}



bool MemoryBuffer::get			( char* buf, size_t nsize ) const
{
	assert( buf != nullptr );
	assert( nsize != 0 );
	assert( nsize >= _memSize );

	memcpy(buf, _buffer, MIN( nsize, _memSize ) );

	return true;
}
