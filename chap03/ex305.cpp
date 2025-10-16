#include <iostream>
#include <string>

using std::string;

int main()
{
    string in;
    string concat("");
    while (std::cin >> in)
    {
        concat += in;
        
        if (in == "*")
            break;
    }
    std::cout << concat << std::endl;

    concat = "";
    while (std::cin >> in)
    {
        concat += in + ", ";
    }

    std::cout << concat << std::endl;

    return 0;
}