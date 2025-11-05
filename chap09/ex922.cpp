#include <iostream>
#include <vector>

int main()
{
    std::vector<int> iv = {1,2,3,4,5,6,7};
    std::vector<int>::iterator iter = iv.begin(), mid = iv.begin() + iv.size()/2;

    int some_val = 3;
    //while(iter != mid)
    //{
    //    if (*iter == some_val)
    //        iv.insert(iter, 2 * some_val);
    //    
    //    ++iter;
    //}

    /*
    Modifying the container inside the loop may potentially invalidate the iterators.
    If for instance, with the new insertion the container must be reallocated in the
    heap then the iterators will be dangling.

    My approach would be to find the value, and then insert externally as such:
    */

    while(iter != mid)
    {
        if (*iter == some_val)
            break;
        ++iter;
    }

    // We know that either it has been found or that it reached the mid point so
    if (iter != mid)
    {
        iv.insert(iter, 2 * some_val);
    }

    // Another alternative is to get the return val of insert, and also recompute mid after the insertion

    return EXIT_SUCCESS;
}