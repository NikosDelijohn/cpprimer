#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int> vec = {1,2,3,4,5,6,7,8,9};
    auto iter = vec.begin();

    while (iter != vec.end())
    {
        if (*iter % 2 )
        {
            iter = vec.insert(iter, *iter);
            // insert, puts the element before the iterator and returns an iterator
            // to the new item. Hence, iter now refers to one-before the element it
            // had prior to the insertion. Another increment must be performed here
            // ++iter in order to avoid an endless loop in case this if is taken.            
        }
        ++iter;
    }

    for (auto &elem: vec)
        std::cout << elem << " " << std::ends;
    std::cout << std::endl;

    return EXIT_SUCCESS;
}