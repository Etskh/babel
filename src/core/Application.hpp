#pragma once

// Core includes
#include "core/Config.hpp"
#include "core/Listener.hpp"


namespace core {

/// The base application that can send events
class Application
{
public:
	/// Constructor
					Application		( const core::Config& config );
	/// Destructor
	virtual     	~Application	( void );


	/// Used to do OnUpdate loops
    Listener		OnUpdate;



public:
	/// Used in the return function of main()
	int				exec			( void );

public:
	/// Called in the event that the Application needs to close
	bool			exit			( int exitCode );

private:
	/// The exit code when the application ends
	int				_exitCode;
	/// Wether or not the application will quit
	bool			_willQuit;
};

} // namespace core
