#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <numeric>

int main()
{
    std::vector<std::pair<std::string, int>> values;
    
    std::string word;
    int val;
    while(std::cin >> word >> val)
    {
        values.push_back(std::make_pair(word, val));
    }

    return EXIT_SUCCESS;
}