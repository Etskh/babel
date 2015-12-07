#pragma once

namespace core {

/// The base application that can send events
class Application
{
public:
	/// Constructor
					Application		( int argc, char** argv );
	virtual     	~Application	( void );
public:
	/// Used in the return function of main()
	int				exec			( void );

public:
	virtual void	OnUpdate		( void );
};

} // namespace core
