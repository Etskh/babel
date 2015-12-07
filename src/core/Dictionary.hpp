#pragma once


#include <vector>
#include <string>

namespace core {

/// Stores string[string]
class Dictionary
{
public:
	/// Typedef to allow us to change the type at will
	typedef std::string Key;
	/// Typedef to allow us to change the type at will
	typedef std::string Value;

public:
	/// Returns a Value ref based on the key - creates one if necessary
	Value&			operator[]	( Key key );
	/// Returns a const Value based on the key - creates one if necessary
	const Value&	operator[]	( Key key ) const;

	/// Returns true if the key is found in the dictionary, false otherwise
	bool			exists		( Key key ) const;

private:
	/// List of keys
	std::vector<std::string>	_keys;
	/// List of values
	std::vector<std::string>	_values;
};

} // namespace core
