#include <iostream>
#include <list>
#include <deque>

int main()
{
    std::list<int> integers = {0,1,2,3,4,5,6,7,9,10};
    std::deque<int> odds;
    std::deque<int> evens;

    for (const int &val: integers)
    {
        !(val % 2) ? evens.push_back(val) : odds.push_back(val);
    }
    
    std::cout << "Even nums are: ";
    for (const int &even: evens)
        std::cout << even << " ";
    std::cout << std::endl;

    std::cout << " Odd nums are: ";
    for (const int &odd: odds)
        std::cout << odd << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}