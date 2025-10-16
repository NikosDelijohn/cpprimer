#include <iostream>
#include <string>
using std::string;

int main()
{
    string a, b;

    std::cin >> a >> b;

    if (a == b)
    {
        std::cout << "Strings are equal" << std::endl;
    }
    else
    {
        if (a > b)
            std::cout << a << " is larger than " << b << std::endl;
        else
            std::cout << b << " is larger than " << a << std::endl; 
    }

    if (a.size() == b.size())
    {
        std::cout << "Equal size of strings!" << std::endl;
    }
    else 
    {
        if (a.size() > b.size())
        {
            std::cout << a << " is longer than " << b << std::endl;
        }
        else
        {
            std::cout << b << " is longer than " << a << std::endl;
        }
    }

    return 0;
}