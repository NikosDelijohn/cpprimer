#include <iostream>
#include <string>
#include <map>

int main()
{

    std::map<std::string, unsigned> word_counter;
    std::string word;

    while(std::cin >> word)
        ++word_counter[word];
    
        // const required because map's .first (keys) are not modifiable (const)
    for (const std::pair<std::string, unsigned> &pair: word_counter)
        std::cout << pair.first << " appeard " << pair.second << " times." << std::endl;

    return EXIT_SUCCESS;
}