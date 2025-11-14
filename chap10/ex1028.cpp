#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

int main()
{
    std::vector<int> source = {1,2,3,4,5,6,7,8,9};

    std::deque<int> f_dest, b_dest, dest;
    
    std::copy(source.begin(), source.end(), std::front_inserter(f_dest));
    for(auto &elem: f_dest) std::cout << elem << " " << std::ends; std::cout << std::endl; // 9...1
    std::copy(source.begin(), source.end(), std::back_inserter(b_dest));
    for(auto &elem: b_dest) std::cout << elem << " " << std::ends; std::cout << std::endl; // 1...9
    std::copy(source.begin(), source.end(), std::inserter(dest, dest.begin()));
    for(auto &elem: dest) std::cout << elem << " " << std::ends; std::cout << std::endl; // 1...9

    return EXIT_SUCCESS;
}