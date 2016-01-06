// Core includes
#include "Serializer.hpp"


using namespace core;

Serializer::Serializer		( Buffer& buffer )
	: _buffer( buffer )
{
	// empty
}

Serializer::~Serializer	( void )
{
	// empty
}

Buffer*	Serializer::buffer	( void )
{
	return &_buffer;
}
