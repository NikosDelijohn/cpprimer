#include <iostream>
#include <string>
#include <cctype>

using std::string;

int main()
{
    std::string line;
    bool capitalize = true;
        
    while(std::getline(std::cin, line))
    {   
        if (!line.size()) // empty line encountered! paragraph changes
        {
            capitalize = false;
        }

        if (capitalize)    
        {
            for (auto it = line.begin(); it != line.end(); ++it)
            {
                *it = std::toupper(*it); 
            }

            std::cout << line << std::endl;

        } 
        else
        {
            std::cout << line << std::endl;
        }
    
    }

}