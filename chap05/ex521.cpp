#include <iostream>
#include <string>
#include <cctype>

using std::string;

int main()
{
    string input;
    string prev;
    bool repetition = false;
    while(std::cin >> input)
    {
        if(input == prev && std::isupper(input[0]) && std::isupper(prev[0]) )  
        {
            repetition = true;
            std::cout << "Halt! '"<< input << "' appeared twice in a row" << std::endl;
            break;
        }

        prev = input;
    }

    if (!repetition)
        std::cout << "no word was repeated" << std::endl;

    return 0;
}