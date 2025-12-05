#include <iostream>
#include <vector>
#include <string>
#include <functional>

int main()
{
    
    std::vector<int> cont_a{1025,1024,1023,1026,1027,1028};
    std::vector<std::string> cont_b{"pooh", "the", "winnie"};
    std::vector<int> cont_c{1,2,3,4,5};

    std::ptrdiff_t n = std::count_if(cont_a.begin(), cont_a.end(), 
        std::bind(std::greater<int>(), std::placeholders::_1, 1024));

    std::cout << "(a) There are " << n << " elements greater than 1024\n";

    auto it = std::find_if(cont_b.begin(), cont_b.end(), 
        std::bind(std::not_equal_to<std::string>(), std::string("pooh"), std::placeholders::_1));
    
    std::cout << "(b) The first element != pooh is '" << *it << "'\n";

    std::transform(cont_c.begin(), cont_c.end(), cont_c.begin(), // assign to the same cont
        std::bind(std::multiplies<int>(), 2,std::placeholders::_1));
    
    std::cout << "(c) Multiplying (x2): ";
    for (auto &elem: cont_c) std::cout << elem << " ";
    std::cout << std::endl;

    return EXIT_SUCCESS;
}