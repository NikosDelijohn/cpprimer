#include <iostream>

int main()
{
    unsigned short vowels = 0u;
    std::string word;
    while (std::cin >> word)
    {
        for (char c: word)
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u')
                ++vowels;
        }
    }

    std::cout << " your text had " << vowels << " vowels" << std::endl;

    return 0;
}