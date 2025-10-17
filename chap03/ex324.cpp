#include <vector>
#include <iostream>

using std::vector;

int main()
{
    vector<int> values = {1,2,3,4,5,60,3,70,80,90,100,11};    
    vector<int> sums(values.size()/2U,0);

    auto start = values.cbegin();
    auto end = values.cend();
    --end;
    unsigned short idx = 0;
    while(start <= end)
    {
        sums[idx] = *start + *end;
        ++start; --end;
        ++idx;
    }
    

    std::cout << "Pairs of sums first with last, second with second to last etc.: " << std::endl;
    for (auto elem : sums) std::cout << elem << std::endl; 

    std::cout << "Adjacent sums" << std::endl;

    for (start = values.cbegin(); start < values.cend(); ++start)
    {
        if (start == values.cbegin())
        {
            std::cout << *start + *(start+1) << std::endl;
        }
        else if (start > values.cbegin() && start < values.cend())
        {
            std::cout << *(start-1) + *start + *(start+1) << std::endl; 
        }
        else
        {
            std::cout << *(start-1) + *start << std::endl;
        }
    }

    return 0;
}