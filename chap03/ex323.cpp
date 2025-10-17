#include <iostream>
#include <vector>

using std::vector;

int main()
{
    vector<int> vals {1,2,3,4,5,6,7,8,9,10};

    for (auto val: vals) std::cout << val << " ";

    for (auto it = vals.begin(); it != vals.end(); it++)
    {
        *it = 2 * (*it);
    }

    std::cout << std::endl;
    
    for (auto val: vals) std::cout << val << " " << std::endl;

    return 0;
}