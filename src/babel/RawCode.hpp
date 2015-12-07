#pragma once


#include <memory>

#include "core/String.hpp"


namespace babel {

/// An example of executable code
class RawCode
{
public:
	/// Handle to dynamically allocate the object
	typedef std::shared_ptr<RawCode>	Handle;

public:
	/// Constructor
					RawCode		( void );

public:
	/// Setting the language after instantiation
	void			setLang		( const char* lang );
	/// Setting the text of the code
	void			setText		( const char* text );

public:
	/// Get the defined language
	const char*		getLang		( void ) const;
	/// Get the code's text
	const char*		getText		( void ) const;

protected:
	/// The language string - is one of a defined few
	core::String	_lang;
	/// The actual text of the code
	core::String	_text;
};

}  // namespace babel
