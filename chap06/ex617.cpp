#include <iostream>
#include <string>

using std::string;

bool has_capital(const string & strval)
{
    for (const char &ch : strval)
        if (ch >= 0x41 && ch <= 0x5A) // In ASCII 'A' = 0x41 and 'Z' = 0x5A 
            return true;

    return false;
}

void to_lowercase(string & strval)
{
    for (char &ch: strval)
        if (ch >= 'A' && ch <= 'Z') // similar to line 9 but more convenient ....
            ch = ch + ('Z' - 'A' + 0x7); // 6 non-letters between UPPERCASE and LOWERCASE letters + 1 to move one past them
}

int main()
{
    std::cout << has_capital("Boom!") << std::endl; // expect 1
    std::cout << has_capital("boom!") << std::endl; // expect 0
    std::cout << has_capital("POW!") << std::endl; // expect 1

    string s1("This MUST be converted TO LOWERCASE");
    std::cout << "Before conversion: " << s1 << std::endl;
    to_lowercase(s1);
    std::cout << "After  conversion: " << s1 << std::endl;
}
