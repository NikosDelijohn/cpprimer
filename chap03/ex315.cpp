#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> user_input;
    std::string val;

    while (std::cin >> val)
        user_input.push_back(val);
    
}