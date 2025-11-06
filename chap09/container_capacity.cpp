#include <iostream>
#include <vector>
using std::vector;

int main()
{
    // capacity() shows how many elements can be stored
    // in the container before re-allocation is needed

    vector<int> veci = {1,2,3,4,5,6};

    // shows 6, 6 
    std::cout << "size: " << veci.size() << ", capacity: " << veci.capacity() << std::endl;
    
    // adding 1 more to re-allocate
    veci.push_back(0);

    // shows 7, 12
    std::cout << "size: " << veci.size() << ", capacity: " << veci.capacity() << std::endl;

    // fill up remaining space without provoking a re-allocation
    while(veci.size() != veci.capacity())
        veci.push_back(1);
    
    // shows 12, 12
    std::cout << "size: " << veci.size() << ", capacity: " << veci.capacity() << std::endl;
    
    // addd 1 more to force re-allocation
    veci.push_back(1);

    // shows 13, 24 (pattern? double from the previous time on each reallocation?)
    std::cout << "size: " << veci.size() << ", capacity: " << veci.capacity() << std::endl;

    // lets say we want to give the remaining space back, we are done!
    veci.shrink_to_fit(); // Its a REQUEST. It may be ignored

    // shows 13, 13 -> request was accepted, container shrunk.
    std::cout << "size: " << veci.size() << ", capacity: " << veci.capacity() << std::endl;

    return EXIT_SUCCESS;
}