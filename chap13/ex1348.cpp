#include <iostream>
#include <vector>
#include "ex1344+1349/string.hpp"

int main()
{
    std::vector<string> vec(200);

    size_t initial_size = vec.size();
    for (size_t idx = 0; idx != initial_size; ++idx)
    {
        vec.push_back("AAAA");
    }
    
    return EXIT_SUCCESS;
}