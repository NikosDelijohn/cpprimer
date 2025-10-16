#include <iostream>
#include <string>
#include <cctype>

using std::string;

int main()
{
    string test = "Heyaaa";

    for (char c : test)
    {
        std::cout << c << std::endl;
    }

    // or we can 

    for (auto c : test)
        std::cout << c << std::endl;

    // or if we want to modify in place

    std::cout << test << std::endl;

    for (auto &c: test) // we get a ref
        c = std::toupper(c);

    std::cout << test << std::endl;

    // but not with ptrs
    //for (auto *p: test)


    return 0;
}