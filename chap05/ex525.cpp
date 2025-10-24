#include <iostream>

int main()
{

    int a,b;
    std::cin >> a>>b;

    resume:
    try
    {
        if (b == 0)
            throw std::runtime_error("division by zero");

        std::cout << a/b << std::endl; 
    }
    catch (std::runtime_error err)
    {
        std::cout << "dividend is 0" << std::endl;
        std::cout << "Give me another number for b!" << std::endl;
        std::cin >> b;

        goto resume; //YIKES! ...
    }
}
