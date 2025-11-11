#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

int main()
{
    std::vector<int> vec;

    std::ifstream input;
    input.open("numbers.txt");

    int val;
    while(input >> val)
        vec.push_back(val);

    auto cc = std::count(vec.begin(), vec.end(), 6);

    std::cout << "5 appeared: " << cc << " times" << std::endl;

    return EXIT_SUCCESS;

}