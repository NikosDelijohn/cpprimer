#include <iostream>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>

int main()
{

    std::map<std::string, unsigned> word_counter;
    std::string word;
    std::set<std::string> ignore = {".", ",", "!", ";"};

    while(std::cin >> word)
    {   
        if (ignore.find(word) != ignore.end())
            continue;
        
        std::string transformed = word;
        std::transform(word.begin(), word.end(), transformed.begin(),
            [](char c) 
            {
                return std::tolower(c);
            }
        );

        ++word_counter[transformed];
    }
    
    // const required because map's .first (keys) are not modifiable (const)
    for (const std::pair<std::string, unsigned> &pair: word_counter)
        std::cout << pair.first << " appeard " << pair.second << " times." << std::endl;

    return EXIT_SUCCESS;
}