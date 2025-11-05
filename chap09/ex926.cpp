#include <iostream>
#include <list>
#include <vector>

int main()
{
    int ia[] = {0,1,1,2,3,5,8,13,21,55,89};

    std::vector<int> vec(std::begin(ia), std::end(ia));
    std::list<int> list(vec.begin(), vec.end());

    auto iter = vec.begin();
    while(iter != vec.end()) // recomputing end at each loop to avoid UB!
    // After each deletion the pointers are invalidated. The values must be
    // recomputed (the vector shrinks!)
    {
        if (*iter % 2) // odd 
        {
            iter = vec.erase(iter);
        }
        else
        {
            ++iter;
        }
    }

    for (auto &elem: vec)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    auto iter2 = list.begin();
    while(iter2 != list.end())
    {
        if (*iter2 % 2) // odd 
        {
            iter2 = list.erase(iter2);
        }
        else
        {
            ++iter2;
        }
    }
    for (auto &elem: list)
    {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}