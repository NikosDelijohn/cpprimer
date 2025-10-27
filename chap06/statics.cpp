#include <iostream>

size_t counter()
{   
    // Initialized once, before the 1st execution
    // reaches the line it checks whether var 'cc'
    // is already initialized. If not, it gets 
    // initialized then. Otherwise previous value 
    // is kept and initializer is ignored.
    static size_t cc = 0u;
    return ++cc;
}

int main()
{
    for (size_t i = 0u; i != 10; ++i)
        std::cout << counter() << std::endl;
    
    return 0;
}