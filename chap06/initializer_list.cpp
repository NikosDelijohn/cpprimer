#include <iostream>
#include <string>

void print(std::initializer_list<std::string> msges)
{
    std::initializer_list<std::string>::iterator begin = msges.begin();
    // - or -
    auto end = msges.end();

    while (begin != end)
        std::cout << *begin++ << std::endl;

}

int main()
{
    std::initializer_list<int> intvals = {1,2,3,4,5,6,7,8};
    // each element is const. i.e., cannot be modified!!

    print({"Arbitrary", "number", "of", "arguments", "of type", "const char *"});

}