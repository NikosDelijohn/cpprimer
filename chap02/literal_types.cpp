#include <iostream>

int main()
{
    
    std::cout << sizeof('A') << " byte(s)" << std::endl;
    std::cout << sizeof(u'A') << " byte(s)" << std::endl;
    std::cout << sizeof(L'A') << " byte(s)" << std::endl;
    std::cout << sizeof(U'A') << " byte(s)" << std::endl;
    std::cout << sizeof(u8"hi!") << " byte(s)" << std::endl;

    return 0;
}