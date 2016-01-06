#pragma once

// Core  includes
#include "core/String.hpp"

namespace gui {

class Template
{
public:
//					Template	( const StringBuffer& reader );
					Template	( const char* data, size_t size );

	virtual			~Template	( void );

public:


}; // class Template


} // namespace
