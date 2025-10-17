#include <vector>
#include <iostream>

using std::vector;

int main()
{
    vector<int> values = {1,2,3,4,5,60,70,80,90,100,11};    
    vector<int> sums(values.size()/2U,0);


    for (decltype(values.size()) idx = 0;
        idx < sums.size(); ++idx)
    {
        sums[idx] = values[idx] + values[values.size() - idx - 1U];
    }

    std::cout << "Pairs of sums first with last, second with second to last etc.: " << std::endl;
    for (auto elem : sums) std::cout << elem << std::endl; 

    std::cout << "Adjacent sums" << std::endl;

    for (decltype(values.size()) idx = 0; idx < values.size(); ++idx)
    {
        if (idx == 0)
            std::cout << values[idx] + values[idx+1] << std:: endl;
        else if (idx > 0 && idx < values.size()-1)
            std::cout << values[idx-1] + values[idx] + values[idx+1] << std::endl;
        else
            std::cout << values[idx-1] + values[idx] << std::endl;
    }   

    return 0;
}