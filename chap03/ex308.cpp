#include <iostream>
#include <string>

using std::string;

int main()
{
    string original_str = "Dummy Text!";

    std::cout << original_str << std::endl;
    // while 
    decltype(original_str.size()) idx = 0;
    while (idx <= original_str.size())
    {
        original_str[idx] = 'X';
        ++idx;
    }
    std::cout << original_str << std::endl;

    original_str = "Dummy Text!";
    // for 
    std::cout << original_str << std::endl;
    for (decltype(original_str.size()) i = 0;
         i < original_str.size(); ++i)
    {
        original_str[i] = 'X';
    }
    std::cout << original_str << std::endl;

    return 0;
}