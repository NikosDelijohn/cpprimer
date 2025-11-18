#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

std::map<std::string, std::string> build_map(std::ifstream &transformations)
{

    std::map<std::string, std::string> retval;

    std::string first_word;
    std::string rest;

    while(transformations >> first_word && std::getline(transformations, rest))
    {
        if (!rest.size())
        {
            throw std::runtime_error("Malformed entry for " + first_word);
        }
        retval[first_word] = rest.substr(1U);
    }
    
    return retval;
}

int main()
{
    std::ifstream transform("ex1133-transformations.txt");
    std::ifstream input("ex1133-input.txt");

    auto t_map = build_map(transform);
    
    std::string line;
    while (std::getline(input, line))
    {   
        std::istringstream ss(line);
        std::string word;

        while(ss >> word)
        {
            auto find_it = t_map.find(word);
            if (find_it != t_map.end())
            {
                std::cout << find_it->second << " ";
            }
            else
            {
                std::cout << word << " ";
            }
        }
        std::cout << std::endl;
    }
    
    return EXIT_SUCCESS;
}