#ifndef BABEL_INCLUDED_ISERIALIZABLE_HPP
#define BABEL_INCLUDED_ISERIALIZABLE_HPP

#include "Serializer.hpp"


namespace core {


/// Interface for serializable objects
class ISerializable
{
public:

	/// Serialize takes in a serializer and should be implemented to write to the serializer
	virtual		bool	serialize	( Serializer& serializer ) const = 0;

	/// deserialize takes in a constant serializer and should be implemented to read from the serializer and write into the object
	virtual		bool	deserialize	( const Serializer& serializer ) = 0;

	/// This is implemented by base-clasess of Serializble
	virtual		bool	describe	( Serializer& serializer ) = 0;

}; // class ISerializable


} // namespace core


#endif // BABEL_INCLUDED_ISERIALIZABLE_HPP
