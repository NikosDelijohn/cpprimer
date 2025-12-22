#include <iostream>
#include <vector>
#include <deque>
#include <array>

template <typename Cont>
void print_elements(const Cont &container)
{
    for (typename Cont::size_type idx=0u; idx < container.size(); ++idx)
    {
        std::cout << container.at(idx) << std::endl;
    }
}

int main()
{

    std::vector<const char *> vec{"Hello", "World!"};
    std::array<double, 3> arr{1.45, 2.59, 3.48};
    std::deque<int> deque{1,2,3,4,5};
    
    print_elements<std::vector<const char*>>(vec);
    print_elements<std::array<double, 3>>(arr);
    print_elements<std::deque<int>>(deque);
    

    return EXIT_SUCCESS;
}