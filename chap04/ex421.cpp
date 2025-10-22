#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int> vals = {0,1,2,3,4,5,6,7,8,9,10,11,12};
    
    for (int &elem: vals)
    {
        (elem % 2) ? elem <<= 1 : elem; // left shift by 1 = mul by 2
    }

    for (int elem: vals)
        std::cout << elem << ' ';
    
    std::cout << std::endl;

    return 0;
}