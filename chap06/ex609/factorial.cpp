#include "ex609.hpp"

unsigned long int factorial(unsigned val)
{
    if (val == 0)
        return 1UL;
    else if (val == 2 || val == 1)
        return val;
    else
        return val * factorial(val - 1UL);
}