#include <iostream>
#include <deque>
#include <string>

int main()
{
    std::deque<std::string> deq;
    std::string word;

    while(std::cin >> word)
        deq.push_back(word);
    
    for(auto it = deq.cbegin(); it != deq.cend(); ++it)
        std::cout << *it << std::endl;

    return EXIT_SUCCESS;
}