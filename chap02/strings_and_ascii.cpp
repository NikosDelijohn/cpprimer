#include <iostream>
#include <string>

int main()
{            
    // index            01234
    std::string test = "test";  
    std::cout << ((test[4] == '\0') ? "NULL" : "WHOOPS!") << std::endl;

    std::cout << '\x4e' 
              << '\x49'
              << '\x4b'
              << '\x4f'
              << '\x53' << std::endl;

    return 0;
}