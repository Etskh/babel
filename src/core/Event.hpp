#pragma once

// STL
#include <functional>

/// Used as a handy in-place way of creating a std::function<>
///		It is accessible to every class that will include a
///		class that inherits from Listener
#define CALLBACK( func ) std::bind1st(std::mem_fun( func ), this)



namespace core {

class Event
{
public:


private:
};


} // namespace core
