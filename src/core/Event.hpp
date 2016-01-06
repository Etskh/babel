#pragma once

// STL
#include <functional>

/// Used as a handy in-place way of creating a std::function<>
///		It is accessible to every class that will include a
///		class that inherits from Listener
#define CALLBACK( func ) std::bind( func, this, std::placeholders::_1 )



namespace core {

/// Object to manage data passed between different events
class Event
{
public:


private:
};


} // namespace core
