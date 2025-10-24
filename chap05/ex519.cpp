#include <iostream>
#include <string>

int main()
{
    std::string s1, s2;

    do
    {
        std::cout << "Gimme 2 str:\n";
        std::cin >> s1 >> s2;

        if (s1.size() < s2.size())
            std::cout << "s1 is less than s2" << std::endl;
        else
            std::cout << "s2 is less than s1" << std::endl;

    } while (true);

    return 0;
}