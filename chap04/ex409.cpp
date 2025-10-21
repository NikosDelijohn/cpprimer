#include <iostream>

int main()
{
    const char *cp = "Hello World";
    
    if (cp && *cp) 
    {
        std::cout << "cp is not nullptr and also not an empty string!" << std::endl;
    }

    return 0;
}