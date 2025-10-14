#include <iostream>
#include "variable_definition.hpp"

extern double pi;
extern const int buffer_size;

int main()
{

    std::cout << pi << std::endl; // 3.14 defined at variable_definition.hpp
    std::cout << buffer_size << std::endl; // 1337 defined at variable_definition.hpp and initialized at runtime. 
    
    // any attempt to re-assign const will break it
    /*
variable_declaration.cpp:20:17: error: assignment of read-only variable ‘buffer_size’
   14 |     buffer_size = 512;
      |     ~~~~~~~~~~~~^~~~~
    */
   
    //buffer_size = 512;

    return 0;
}

