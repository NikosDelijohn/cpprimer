#include <iostream>
#include <string>
#include <cctype>

using std::string;

int main()
{
    string in;

    while (std::getline(std::cin, in))
    {
        for (char &c: in)
        {
            if (std::ispunct(c))
            {
                c = '\0';
            }
        }
        
        std::cout << in << std::endl;
    }

    return 0;
}