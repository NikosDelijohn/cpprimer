#include <iostream>
#include <vector>

std::vector<int>::iterator
is_inside(std::vector<int>::iterator beg,
          std::vector<int>::iterator end,
          int value)
{
    while (beg != end)
    {
        if (*beg == value)
            return beg;
        ++beg;
    }
    return end; // not found
}

int main()
{
    std::vector<int> vals = {1, 2, 3, 4, 5, 6};

    for (int test : {-1, 1, 15, 6})
    {
        auto it = is_inside(vals.begin(), vals.end(), test);
        if (it != vals.end())
            std::cout << "found: " << *it << std::endl;
        else
            std::cout << "not found: " << test << std::endl;
    }
}   