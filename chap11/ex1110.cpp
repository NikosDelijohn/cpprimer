#include <iostream>
#include <vector>
#include <list>
#include <map>

int main()
{
    std::map<std::vector<int>::iterator, int> mapping;

    // this is wrong although it may compile.
    // lists provide bidirectional iterators which do not 
    // define relop arithmetic. This is needed for a mapping
    // in order to define a strict weak ordering however. 
    // Thus this statement may yield UB
    std::map<std::list<int>::iterator, int> mapping2;

    // Correct way is to define an ordering.
    auto cmp = [](const std::list<int>::iterator &a,
                const std::list<int>::iterator &b) {
        return &*a < &*b; // compare the addresses of the elements
    };

    std::map<std::list<int>::iterator, int, decltype(cmp)> mapping2(cmp);
    
    return EXIT_SUCCESS;

}