#include <iostream>
#include <string>
using std::string; 

bool is_empty(string &s)
{
    return s.empty();
}

int main()
{
    // problem is that it works with strings like such

    string s1 = "Hello Mate!";
    is_empty(s1);
    
    char c_s1[5] = {'H', 'e', 'l', 'l', 'o'};
    is_empty(s1);

    // but not with const strings like 
    const char c_s2[] = "Testing!";
    //is_empty(c_s2); // Nope
    //is_empty(""); // Nope

    // Either ways, the core functionality doesn't include
    // modifying the passed object. Hence not defining the 
    // parameter as const limits the functionallity of the
    // function to even more specific types.
    // Specifically it does not accept:
    //    A const std::string
    //    A string literal (like "Hello")
    //    A const char[]

    return 0;
}