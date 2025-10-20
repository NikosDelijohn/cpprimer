#include <vector>
#include <iostream>

using std::vector;

int main()
{
    vector<int> s_nums {9, 100, 120, 256, 735, 800}; 

    vector<int>::const_iterator cb = s_nums.cbegin();
    vector<int>::const_iterator ce = s_nums.cend();

    std::cout << "Diff = " << ce - cb << std::endl; 

    int search_for;
    std::cin >> search_for;

    auto start = cb;
    auto end = ce;
    auto mid = start + (end - start) / 2U;

    std::cout << "start = " << std::distance(s_nums.cbegin(), start) << " :" << *start
    << "    mid = " << std::distance(s_nums.cbegin(), mid) << " :" << *mid 
    << "    end = " << std::distance(s_nums.cbegin(), end) << " :" << *end << std::endl;

    std::cout << " ============== " << std::endl;

    while (*mid != search_for && mid != start)
    {

        if (search_for < *mid)
        {
            end = mid;
        }
        else 
        {
            start = mid;
        }

        mid = start + (end - start)/2U;

        std::cout << "start = " << std::distance(s_nums.cbegin(), start) << " :" << *start
        << "    mid = " << std::distance(s_nums.cbegin(), mid) << " :" << *mid 
        << "    end = " << std::distance(s_nums.cbegin(), end) << " :" << *end << std::endl;
    

        std::cout << " ============== " << std::endl;
    }

    if (*mid == search_for)
    {
        std::cout << "Value found: " << *mid << std::endl;
    }
    else 
    {
        std::cout << "Value does not exist!" << std::endl;
    }

    return 0;
}