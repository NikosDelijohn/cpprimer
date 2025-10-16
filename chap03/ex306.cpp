#include <iostream>
#include <string>

using std::string;

int main()
{
    string original_str = "Dummy Text!";

    std::cout << "Original :" << original_str << std::endl;

    for (char &c: original_str)
        c = 'X';

    std::cout << "Modified :" << original_str << std::endl;
    
    return 0;
}