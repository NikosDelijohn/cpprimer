#include <iostream>

int main()
{
    const char ca[] = {'H','e','l','l','o'};
    const char *cp = ca;

    while (*cp)
    {
        std::cout << *cp << std::endl;
        ++cp;
    }
    
    // Because this is not null terminated, the test will continue after printing each
    // character at a new line to print whatever until it reaches some thing invalid 
    // (segfault) or randomly hit a '\0' in memory. Undefined after first 5 iterations!
    // although most probably it will work as-is it is not correct !

    return 0;
}