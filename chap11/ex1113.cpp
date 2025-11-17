#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <numeric>

int main()
{
    std::vector<std::pair<std::string, int>> values;
    std::vector<std::pair<std::string, int>> values2;
    std::vector<std::pair<std::string, int>> values3;
    std::vector<std::pair<std::string, int>> values4;
    
    std::string word;
    int val;
    
    while(std::cin >> word >> val)
    {
        // 1st way
        values.push_back(std::make_pair(word, val));

        // 2nd way
        std::pair<std::string, int> pair(word,val);
        values2.push_back(pair);

        // 3rd way
        std::pair<std::string, int> pair2 = {word, val};
        values3.push_back(pair);
        
        // 4th way
        values4.emplace_back(word, val);
    }   

    return EXIT_SUCCESS;
}