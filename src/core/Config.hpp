#pragma once

// STL
#include <string>
#include <map>


#include "core/String.hpp"

namespace core {


class Config
{
public:
						Config		( void );
						Config		( int argc, char** argv );

public:
	core::String&		operator[]	( const char* key );
	//const core::String& operator[]	( const char* key ) const;

public:
	std::map<std::string, core::String>	_vals;
};

} // namespace core
