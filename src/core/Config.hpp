#pragma once

// STL
#include <string>
#include <map>


#include "core/String.hpp"

namespace core {

/// This is used to provide configuration options for various systems
class Config
{
public:
	/// Consturcotr
						Config		( void );
	/**
	 * Constructs from main()'s argc and argv, and parses the arguments
	 *
	 * @param argc : the argc passed from main
	 * @param argv : the argv passed from main
	 */
						Config		( int argc, char** argv );

	/// Operator to get the value of each item
	core::String&		operator[]	( const char* key );

private:
	/// The dictionary of values
	std::map<std::string, core::String>	_vals;
};

} // namespace core
