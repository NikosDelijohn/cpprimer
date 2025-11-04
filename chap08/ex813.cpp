#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "../help.hpp"
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " filename.txt" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream input_file(argv[1]);
    
    struct person_info
    {
        std::string name;
        std::vector<std::string> phones;
    };

    std::string line, word;
    std::istringstream record;
    std::vector<person_info> people;

    while(getline(input_file, line))
    {
        person_info info;
        record.str(line);

        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        
        // remember to clear the state. when eof is reached 
        // state will be eofbit.
        record.clear(record.rdstate() & ~std::ios::eofbit & ~std::ios::failbit);
        // or safer, just clear(std::ios::goodbit)
        people.push_back(info);
    }

    for (auto &p: people)
    {
        std::cout << p.name << ' ';
        for (auto &num: p.phones)
        {
            std::cout << num << ' ';
        }
        std::cout << std::endl;
    }

    return EXIT_SUCCESS;
}