#ifndef BABEL_INCLUDED_SERIALIZABLE_HPP
#define BABEL_INCLUDED_SERIALIZABLE_HPP

#include "ISerializable.hpp"


namespace core {


/// Interface for serializable objects
class Serializable
	: public ISerializable
{
public:

	/// Serialize takes in a serializer and should be implemented to write to the serializer
	virtual		bool	serialize	( Serializer& serializer ) const;

	/// deserialize takes in a constant serializer and should be implemented to read from the serializer and write into the object
	virtual		bool	deserialize	( const Serializer& serializer );

}; // class Serializable


} // namespace core


#endif // BABEL_INCLUDED_SERIALIZABLE_HPP
