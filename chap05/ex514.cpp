#include <iostream>
#include <string>

int main()
{

    std::string curr;
    std::string prev;
    std::string top_word;
    unsigned short top_cc = 1u;

    unsigned short cc = 1u;
    std::string word; 

    while(std::cin >> curr)
    {

        if (prev == curr)
        {
            ++cc;
            if (cc > top_cc)
            {
                top_cc = cc;
                top_word = curr;
            }
        }
        else
        {   //reset 
            cc = 1u;
        }

        prev = curr;
    }

    std::cout << "the word " << top_word << " occured " << top_cc << " times" << std::endl;

    return 0;
}