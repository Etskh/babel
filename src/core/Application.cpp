
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
	while (!_willQuit){
		this->OnUpdate();
	}
	return _exitCode;
}

void	Application::OnUpdate		( void )
{

}

bool	Application::exit			( int exitCode )
{
	bool wasGoingToQuitAnyway = _willQuit;
	_exitCode = exitCode;
	_willQuit = true;
	return wasGoingToQuitAnyway;
}
