#include <iostream>
#include <vector>

#include "blob.hpp"
#include "blobptr.hpp"

int main()
{   

    Blob<int> integers;
    auto beg = integers.begin();

    integers.push_back(1);

    auto val = integers.pop_back();
    integers.push_back(1);
    integers.push_back(2);
    integers.push_back(3);
    integers.push_back(4);
    integers.push_back(5);
    integers.push_back(4);
    integers.push_back(3);
    integers.push_back(2);
    integers.push_back(1);

    std::cout << val << std::endl;

    while(beg != integers.end())
        std::cout << *beg++ << std::endl;
    
    // 
    std::vector<const char*> svec{"This", "Is", "Something", "New!"};
    Blob<const char*> strings(svec.begin(), svec.end());
    auto beg2 = svec.begin();
    
    while(beg2 != svec.end())
        std::cout << *beg2++ << std::endl;

    return EXIT_SUCCESS;
}