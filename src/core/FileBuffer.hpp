#pragma once


// Core includes
#include "BufferImpl.hpp"

namespace core {

class FileBuffer
	: public BufferImpl
{
public:
				FileBuffer	( const char* path );
	virtual		~FileBuffer	( void );


	

};


} // namespace core
