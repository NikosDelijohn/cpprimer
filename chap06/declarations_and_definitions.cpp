#include <iostream>
#include "declarations_and_definitions.hpp"

int some_function(int x, int y)
{
    ++x; ++y;
    return x * y;
    // this function has a matching prototype in the included header
}

int some_problematic_function(int z, int w)
{
    // this function does not have a matching prototype in the header
    return z + w;
}
