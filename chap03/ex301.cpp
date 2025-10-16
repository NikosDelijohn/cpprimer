#include <iostream>
#include <string>

using std::string;

int main()
{
    string in; 

    // one whole line at a time
    while(std::getline(std::cin, in))
    {
        std::cout << in << std::endl;

        if (in == "***") // sentinel val
            break;
    }

    while(std::cin >> in)
    {
        std::cout << in << std::endl;
    }

    return 0;
}