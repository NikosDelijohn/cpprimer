#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <algorithm>

bool int_bigger_than_strlen(const int &uintval, const std::string &str)
{
    return uintval > str.size();
}

int main()
{
    std::vector<int> ivec = {1,2,3,4,5,6,7,8,9,10};
    std::string word = "Meshuggah"; // 9 chars 

    auto found_iter = std::find_if(ivec.begin(), ivec.end(), std::bind(
        int_bigger_than_strlen,
        std::placeholders::_1,
        word)
    );

    std::cout << ((found_iter != ivec.end()) ? ("Element found: " + std::to_string(*found_iter)) : "Not found") << std::endl;

    return EXIT_SUCCESS;
}