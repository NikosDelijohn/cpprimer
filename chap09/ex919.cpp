#include <iostream>
#include <list>
#include <string>

int main()
{
    std::list<std::string> list;
    std::string word;

    while(std::cin >> word)
        list.push_back(word);

    for(auto it = list.cbegin(); it != list.cend(); ++it)
        std::cout << *it << std::endl;

    
    return EXIT_SUCCESS;
}