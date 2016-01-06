
#include "Application.hpp"

using namespace core;

Application::Application	( const core::Config& )
	: _exitCode (0)
	, _willQuit (false)
{
	// empty
}

Application::~Application	( void )
{
	// empty
}



int		Application::exec		(void)
{
	Event event;

	// Call the OnInit callbacks
	OnInit.call(event);

	while (!_willQuit) {
		OnUpdate.call(event);
	}

	// Call the OnKill callbacks
	OnKill.call(event);

	return _exitCode;
}



bool	Application::exit			( int exitCode )
{
	bool wasGoingToQuitAnyway = _willQuit;
	_exitCode = exitCode;
	_willQuit = true;
	return wasGoingToQuitAnyway;
}
