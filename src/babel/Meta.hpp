#ifndef BABEL_INCLUDED_META_HPP
#define BABEL_INCLUDED_META_HPP

#include "core/String.hpp"
#include "core/Array.hpp"


namespace babel {

/// This is the meta tag for every babel object
struct Meta
{
public:
	/// Timestamp when the object was created
	unsigned int	created_on;
	/// Timestamp when the object was last modified
	unsigned int	modified_on;
	/// An array of the author names
	core::Array		authors;
	/// A hash of the version - always different
	core::String	version_hash;
};


} // namespace babel

#endif // BABEL_INCLUDED_META_HPP
