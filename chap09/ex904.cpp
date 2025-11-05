#include <iostream>
#include <vector>

bool is_inside(std::vector<int>::const_iterator beg,
               std::vector<int>::const_iterator end, int value)
{
  
    if (beg == end)
    {
        return false;
    }
    
    while(beg != end)
    {
        if(*beg++ == value)
            return true;
    }

    return false;
}

int main()
{

    std::vector<int> vals = {1,2,3,4,5,6};
    auto beg = vals.cbegin();
    auto end = vals.cend();

    std::cout << std::boolalpha << is_inside(beg, end, -1) << std::endl;
    std::cout << std::boolalpha << is_inside(beg, end, 1) << std::endl;
    std::cout << std::boolalpha << is_inside(beg, end, 15) << std::endl;
    std::cout << std::boolalpha << is_inside(beg, end, 6) << std::endl;

}