#include "RawCode.hpp"

using namespace babel;

RawCode::RawCode ( void )
	: _lang("javascript")
	, _text("")
{
	// empty
}


void		RawCode::setLang		( const char* lang )
{
	_lang = lang;
}

void		RawCode::setText		( const char* text )
{
	_text = text;
}

const char*	RawCode::getLang		( void ) const
{
	return _lang.c_str();
}

const char*	RawCode::getText		( void ) const
{
	return _text.c_str();
}
