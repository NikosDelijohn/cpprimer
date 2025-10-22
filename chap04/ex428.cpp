#include <iostream>

int main()
{
    std::cout << "size of int = " << sizeof(int) * 8  << std::endl;
    std::cout << "size of short = " << sizeof(short) * 8 << std::endl;
    std::cout << "size of long = " << sizeof(long) * 8 << std::endl;
    std::cout << "size of long long = " << sizeof(long long) * 8 << std::endl;
    std::cout << "size of char = " << sizeof(char) * 8 << std::endl;
    std::cout << "size of wchar = " << sizeof(wchar_t) * 8 << std::endl;
    std::cout << "size of char16 = " << sizeof(char16_t) * 8 << std::endl;
    std::cout << "size of char32 = " << sizeof(char32_t) * 8 << std::endl;
    std::cout << "size of float = " << sizeof(float) * 8 << std::endl;
    std::cout << "size of bool = " << sizeof(bool) * 8 << std::endl;
    std::cout << "size of double = " << sizeof(double) * 8 << std::endl;
    std::cout << "size of long double = " << sizeof(long double) * 8 << std::endl;

    return 0;
}