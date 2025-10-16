#include <iostream>
#include <string>

using std::string;

int main()
{
    const string s = "KEEP OUT!";

    for (auto &c: s) // fine, c is a ref to const char (low-level const)
    {
        std::cout << c << std::endl;
    }

    return 0;
}