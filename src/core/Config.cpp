#include "Config.hpp"


using namespace core;

Config::Config		( void )
{
	// empty
}

Config::Config		( int , char** )
{
	// TODO: Do this in here
}


core::String&		Config::operator[]( const char* key )
{
	return _vals[key];
}

/*const core::String& Config::operator[]( const char* key ) const
{
	return _vals[key];
}*/
