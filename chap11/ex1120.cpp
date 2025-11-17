#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> word_counter;

    std::string word;
    while(std::cin >> word)
    {
        auto ret = word_counter.insert({word, 1});
        if (!ret.second)
            ++ret.first->second;
    }

    for (const std::pair<std::string, unsigned> &pair: word_counter)
        std::cout << pair.first << " appeard " << pair.second << " times." << std::endl;

    return EXIT_SUCCESS;
}