#pragma once
#include <iostream>

class DebugDelete
{
public:
    DebugDelete() = default;
    template <typename Object>
    void operator()(Object* ptr) const
    {
        std::cout << "Deleting ptr: " << std::endl;
        delete ptr; 
    }
};