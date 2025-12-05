#include <iostream>
#include <vector>
#include <functional>

int main() 
{
    std::vector<int> candidates {1,2,3,4,5,6,7,8,9};
    int value = 122;

    auto it = candidates.begin();

    while( (it = std::find_if(it, candidates.end(),
            std::bind(std::equal_to<int>(),
                      std::bind(std::modulus<int>(), value, std::placeholders::_1),
                      0))) != candidates.end())
    {
        std::cout << "Divisor: " << *it << "\n";
        ++it;
    }

    return EXIT_SUCCESS;
}
