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


namespace core {

/// Listener functor-ish, used to accumulate callbacks
class Listener
{
public:
	/// Callback object to store event
	typedef std::function<bool (Event&)>	Callback;

	/// Constructor
				Listener		( void );
	/// Deconstructor
	virtual		~Listener		( void );


	/// Add a callback to this event-listener
	inline bool	operator+=		( Callback callback );


	/// Actual functiony thing for adding callbacks - use += instead. It's cooler.
	bool		addCallback		( Callback callback );


	/// Syntactic sugar for call function
	//bool		operator()		( Event& event );


	/**
	 * Cycles through all attached listeners to this object, and calls
	 * each in turn.
	 *
	 * @param event : Event& the event that is given to each callback
	 *
	 * @returns true always
	 */
	bool		call			( Event& event );


private:
	/// List of the callbacks, called on this->call(event)
	std::list<Callback>	_callbacks;


}; // class Listener




bool	Listener::operator+=	( Callback callback )
{
	return addCallback(callback);
}



} // namespace core
