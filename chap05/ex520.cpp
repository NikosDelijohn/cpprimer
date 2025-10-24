#include <iostream>
#include <string>

using std::string;

int main()
{
    string input;
    string prev;
    bool repetition = false;
    while(std::cin >> input)
    {
        if(input == prev)  
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