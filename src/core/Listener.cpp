
#include "Listener.hpp"

using namespace core;

Listener::Listener	( void )
{
	// empty
}
Listener::~Listener	( void )
{
	// empty
}


bool	Listener::operator+=	( Callback callback )
{
	return addCallback(callback);
}


bool	Listener::addCallback	( Callback callback )
{
	_callbacks.push_back(callback);
	return true;
}



/*bool	Listener::operator()	( Event& event )
{
	return this->call(event);
}
*/



bool	Listener::call		( Event& event )
{
	auto callback = _callbacks.begin();
	bool captured = true;
	while ( callback != _callbacks.end() )
	{
		captured = captured && (*callback)(event);
		callback++;
	}
	return captured;
}
