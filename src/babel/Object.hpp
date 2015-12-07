/*


*/
#pragma once

#include <memory>
#include <list>

#include "core/String.hpp"
#include "core/Array.hpp"

#include "RawCode.hpp"


namespace babel {

/// Babel object is a container for transmuting to source-code
class Object
{
public:
	/// Handle for dynamic allocation
	typedef std::shared_ptr<Object>	Handle;

public:
	/// Factory method for instantiation
	static Handle			create		( const core::String name );

public:
	/// Runs the Object
	// TODO(Etskh): add arguments in this function (as an array)
	int						run			( const core::Array& args );
	/// Adds a child to the object
	void					addChild	( const Object::Handle child );

public:
	/// Sets the raw code for the object
	void					setRawCode	( RawCode::Handle rawCode );

public:
	/// Retrieves the parent for the Object
	const Object::Handle	getParent	( void ) const;
	/// Returns the description string as a c-string
	const char*				getDesc		( void ) const;
	/// Returns the name of the Object
	const char*				getName		( void ) const;

protected:
	/// Constructor
	explicit				Object		( const core::String& name );

private:
	/// This is the executable code
	RawCode::Handle				_rawCode;
	/// The name
	core::String				_name;
	/// The documentation string
	core::String				_desc;
	/// A list of child Objects
	std::list<Object::Handle>	_children;
	/// A reference to itself, for assigning parents
	mutable Object::Handle		_self;
	/// A reference to its parent (for traversal)
	mutable Object::Handle		_parent;
};

}  // namespace babel
