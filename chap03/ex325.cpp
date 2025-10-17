#include <iostream>
#include <vector>

using std::vector;

int main()
{
    std::vector<int> bins(11);
    std::vector<int> read_values;
    
    int val;
    while (std::cin >> val)
        read_values.push_back(val);

    auto bin_iter = bins.begin();

    for (auto it = read_values.cbegin(); it != read_values.cend(); ++it)
    {
        if (*it <= 100)
            ++ *(bin_iter + *it/10);
    }
 
    for (auto bin : bins) std::cout << bin << " ";

    std::cout << std::endl;
    
    return 0;
}