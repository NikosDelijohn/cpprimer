#include <iostream>
#include <vector>
#include <deque>
#include <array>

template <typename Cont>
void print_elements(const Cont &container)
{
    typename Cont::const_iterator cbegin = container.cbegin();
    typename Cont::const_iterator cend = container.cend();

    while(cbegin != cend)
        std::cout << *cbegin++ << std::endl;
}

int main()
{

    std::vector<const char *> vec{"Hello", "World!"};
    std::array<double, 3> arr{1.45, 2.59, 3.48};
    std::deque<int> deque{1,2,3,4,5};
    
    print_elements(vec);
    print_elements(arr);
    print_elements(deque);
    

    return EXIT_SUCCESS;
}