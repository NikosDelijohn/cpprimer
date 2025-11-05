#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a = {1,2,3,5/*,6,7*/};
    std::vector<int> b = {1,2,3,5};

    std::cout << "Vectors are: " << ((a == b) ? "equal" : "unequal") << std::endl;
}