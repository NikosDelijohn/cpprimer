#include <iostream>
#include <vector>
#include <list>

int main()
{
    std::list<int> a = {1,2,3,5,6/*,7*/};
    std::vector<int> b = {1,2,3,5};

    std::cout << "Containers are: " << ((std::vector<int>(a.begin(), a.end()) == b) ? "equal" : "unequal") << std::endl;
}