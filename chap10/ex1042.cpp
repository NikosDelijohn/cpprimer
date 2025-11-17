#include <iostream>
#include <list>
#include <string>
#include <algorithm>

void print_list(std::list<std::string> &list)
{
    for (auto &elem: list)
        std::cout << elem << " ";
    std::cout << std::endl;
}

int main()
{
    std::list<std::string> words = {"There", "indeed", "are", "indeed", "are", "some", "some"};
    
    print_list(words);

    words.sort();

    print_list(words);

    words.unique();

    print_list(words);
    
    return EXIT_SUCCESS;
}