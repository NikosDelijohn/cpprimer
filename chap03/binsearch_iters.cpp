#include <vector>
#include <iostream>

using std::vector;

int main()
{

    vector<int> sorted_numbers = {1, 2, 40, 49, 50, 52, 53, 250, 500, 1000, 102031};

    auto start = sorted_numbers.cbegin();
    auto end = sorted_numbers.cend();
    auto mid = start + (end-start)/2;

    int looking_for = 2;

    while(looking_for != *mid && end != mid)
    {
        if (looking_for < *mid)
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
        mid = start + (end-start)/2;
    }

    if (end == mid)
    {
        std::cout << "Value does not exist!" << std::endl;
    }
    else
    {
        std::cout << "Value found at pos: " << (mid - sorted_numbers.begin()) << std::endl;
    }
    
}