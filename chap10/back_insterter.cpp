#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

int main()
{
    std::vector<int> ivec;

    // std::fill_n(ivec.begin(), 10, 0);
    
    // This statement is in error and dangerous.
    // It attempts to write! to an empty container
    // 10 elements to value 0. However, the container
    // is not allocated. Has no elements inside. -> UB

    // ivec.reserve(10);
    // std::fill_n(ivec.begin(), 10, 0);

    // Still NOT ok! Reserve simply allocates capacity
    // Does NOT create these 10 elements however. So still
    // we are writing into an empty vector! -> UB

    ivec.resize(10);
    std::fill_n(ivec.begin(), 10, 0);
    // This is OK! Resize either shrinks or expands
    // the container by creating elements. It does 
    // not just allocate space. Hence the call to fill_n
    // is valid now. We are changing the values of 10 elements
    // to 0.

    // Or alternatively, we can use back inserters, defined 
    // at the iterator header. These iterators can be used to
    // create new elements by invoking the push_back method
    // of the container that they are bound to.
    std::vector<int> ivec2;
    std::back_insert_iterator<std::vector<int>> back_iter = std::back_inserter(ivec2); // or auto back_iter = ...
    std::fill_n(back_iter, 10,0);

    // -> Containers with no push_back cannot use the back_inserter (e.g., forward list)

    std::vector<int> vec3;
    auto iter2 = std::back_inserter(vec3);

    std::copy(ivec2.cbegin(), ivec2.cend(), iter2);

    return EXIT_SUCCESS;
}