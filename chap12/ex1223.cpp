#include <iostream>
#include <new>
#include <string>
#include <cstring>

char* concat(const char *a, const char *b)
{
    char *new_str = new char[std::strlen(a) + std::strlen(b) + 1]; // +1 for NULL terminator
    std::strcpy(new_str, a);
    std::strcat(new_str, b);

    return new_str;
}

std::string concat2(const std::string a, const std::string b)
{
    return a + b;
}

int main()
{

    char *cc = concat("this is ", "SPARTA!");
    std::cout << cc << std::endl; // prints the whole string! not the ptr address
    delete [] cc;

    std::cout << concat2("this is ", "SPARTA!") << std::endl;

    return EXIT_SUCCESS;
}