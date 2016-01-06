


// Util includes
#include "JSONSerializer.hpp"

using namespace util;



// JSONSerializer
JSONSerializer::JSONSerializer	( core::Buffer& buffer )
	: core::Serializer( buffer )
	, _indentIndex (0)
	, _indent ("")
	, _indentCharacter(' ')
	, _indentCount(2)
{
	// empty
}



JSONSerializer::~JSONSerializer	( void )
{
	// empty
}




void	JSONSerializer::begin			( const char* objectType )
{
	// If this is the first object, put the braces around the edges
	if(_indentIndex == 0) {
		std::string output;
		output += getIndent();
		output += "{\n";
		buffer()->writeString( output.c_str() );
		indent();
	}

	std::string output;
	output += getIndent();
	output += "\"";
	output += objectType;
	output += "\" : {\n";

	buffer()->writeString( output.c_str() );
	indent();
}




void	JSONSerializer::end				( void )
{
	unindent();

	std::string output;
	output += getIndent();
	output += "},\n";

	buffer()->writeString( output.c_str() );

	if(_indentIndex == 1) {
		end();
	}
}




void	JSONSerializer::addString		( const char* name, const char* value )
{
	char buf[256];
	sprintf( buf, "%s\"%s\" : \"%s\", \n", getIndent(), name, value );

	buffer()->writeString( buf );
}





void	JSONSerializer::begin			( const char* objectType ) const
{
	// empty
}



void	JSONSerializer::end				( void ) const
{
	// empty
}



void	JSONSerializer::getString		( const char* name, OUT core::String* field ) const
{
	// empty
}





void	JSONSerializer::indent			( void )
{
	++_indentIndex;
	_indent = "";
	for( size_t i=0; i<_indentIndex*_indentCount; ++i) {
		_indent += _indentCharacter;
	}
}





void	JSONSerializer::unindent			( void )
{
	--_indentIndex;
	_indent = "";
	for( size_t i=0; i<_indentIndex*_indentCount; ++i) {
		_indent += _indentCharacter;
	}
}





const char*	JSONSerializer::getIndent		( void )
{
	return _indent.c_str();
}
