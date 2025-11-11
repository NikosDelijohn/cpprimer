#include <iostream>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>

int main()
{
    std::list<std::string> vec;

    std::back_insert_iterator<std::list<std::string>> backins = std::back_inserter(vec);

    std::ifstream input;
    input.open("numbers.txt");

    std::string val;
    while(input >> val)
        vec.push_back(val);

    auto cc = std::count(vec.begin(), vec.end(), "6");

    std::cout << "5 appeared: " << cc << " times" << std::endl;

    return EXIT_SUCCESS;

}