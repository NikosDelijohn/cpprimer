#include <iostream>
#include <vector>

#include "blob.hpp"

int main()
{   

    Blob<int> integers;

    integers.push_back(1);

    auto val = integers.pop_back();
    std::cout << "Popped value was " << val << std::endl;

    integers.push_back(1);
    integers.push_back(2);
    integers.push_back(3);
    integers.push_back(4);
    integers.push_back(5);
    integers.push_back(4);
    integers.push_back(3);
    integers.push_back(2);
    integers.push_back(1);


    auto elements = integers.size();

    std::cout << "Printing all INT elements\n";
    for (auto idx = 0u; idx < elements; ++idx)
        std::cout << integers[idx] << std::endl;
    
    std::vector<const char*> svec{"This", "Is", "Something", "New!"};
    Blob<const char*> strings(svec.begin(), svec.end());

    elements = strings.size();

    std::cout << "Printing all STR elements\n";
    for (auto idx = 0u; idx < elements; ++idx)
        std::cout << strings[idx] << std::endl;
    


    return EXIT_SUCCESS;
}