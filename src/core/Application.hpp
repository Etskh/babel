#pragma once

// Core includes
#include "core/Config.hpp"

namespace core {

/// The base application that can send events
class Application
{
public:
	/// Constructor
					Application		( const core::Config& config );
	virtual     	~Application	( void );
public:
	/// Used in the return function of main()
	int				exec			( void );

public:
	virtual void	OnUpdate		( void );

public:
	bool			exit			( int exitCode );

private:
	int				_exitCode;
	bool			_willQuit;
};

} // namespace core
