/*

	Usage:

	public:
		Listener	OnUpdate;

		// Later
		OnUpdate += Callback( std::function( ) );

*/
#pragma once


// STL
#include <functional>
#include <list>

// Core includes
#include "core/Event.hpp"

/// Used as a handy in-place way of creating a std::function<>
///		It is accessible to every class that will include a
///		class that inherits from Listener
#define CALLBACK ( X ) std::bind1st(std::mem_fun( X ), this);


namespace core {

class Listener
{
public:
	typedef std::function<bool (Event&)>	Callback;


				Listener		( void );
	virtual		~Listener		( void );


	/// Add a callback to this event-listener
	bool		operator+=		( Callback callback );


	/// Actual functiony thing for adding callbacks - use += instead. It's cooler.
	bool		addCallback		( Callback callback );


	/// Syntactic sugar for call function
	bool		operator()		( Event& event );


	/// Call the event and fire callbacks
	bool		call			( Event& event );

private:
	std::list<Callback>	_callbacks;
};


} // namespace core
