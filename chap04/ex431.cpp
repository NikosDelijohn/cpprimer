#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int> ivec {10,20,30,40,50,60,70};

    vector<int>::size_type cnt = ivec.size();

    // the loops are equivalent because the albeit at the point of increment 
    // postfix returns the old value, when we enter the loop, the new value 
    // is used! However, prefix is preferable to avoid redundant copying of 
    // loop control variables.
    for(vector<int>::size_type ix = 0u; ix != ivec.size(); ix++, cnt--)
    {
        ivec[ix] = cnt;
    }

    for (auto e: ivec)
    {
        std::cout << e << " ";
    }
    
    std::cout<<std::endl;

    return 0;
}