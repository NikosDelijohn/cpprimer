#include <iostream>
#include <string>
using std::string;

string (& does_nothing(string (&arr)[10]))[10]
{
    return arr;
}

typedef string ten_strings[10];
ten_strings &equiv1(ten_strings &arr)
{
    return arr;
}

using ten_sstrings = string[10];
ten_sstrings &equiv2(ten_sstrings &arr)
{
    return arr;
}

string dummy[10];
decltype(dummy) &equiv3(decltype(dummy) &arr)
{
    return arr;
}

int main()
{
    string strings[10] = {"h", "e", "l", "l", "o", " ", "!"};

    string  (&r)[10] = does_nothing(strings);

    for (auto &elem: r)
        std::cout << elem << ' ';
    std::cout << std::endl;

    // ------
    
    string strings2[10] = {"h", "e", "l", "l", "o", " ", "!"};
    string  (&r2)[10] = does_nothing(strings2);
    for (auto &elem: r2)
        std::cout << elem << ' ';
    std::cout << std::endl;

    // ------
    
    string strings3[10] = {"h", "e", "l", "l", "o", " ", "!"};
    string  (&r3)[10] = does_nothing(strings3);
    for (auto &elem: r3)
        std::cout << elem << ' ';
    std::cout << std::endl;

    // ------
    
    string strings4[10] = {"h", "e", "l", "l", "o", " ", "!"};
    string  (&r4)[10] = does_nothing(strings4);
    for (auto &elem: r4)
        std::cout << elem << ' ';
    std::cout << std::endl;

    return 0;
}