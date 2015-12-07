#pragma once

namespace core {

/// The base application that can send events
class Application
{
public:
	/// Constructor
			Application	( int argc, char** argv );

public:
	/// Used in the return function of main()
	int		exec		(void);
};

} // namespace core
