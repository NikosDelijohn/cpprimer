#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

void print_vec(const vector<int> &vec)
{
    static size_t current_index = 0u;
#ifndef NDEBUG
    std::cout << __LINE__ << " Processing Element: " << current_index << std::endl;
#endif
    if (current_index == vec.size())
    {
        std::cout << std::endl;
        return;
    }

    std::cout << vec[current_index++] << ' ';
    print_vec(vec);
}

int main()
{
    vector<int> vec = {1,2,3,4};
    print_vec(vec);
}

