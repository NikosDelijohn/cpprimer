#include <iostream>
#include <string>
#include <fstream>


int main()
{

    std::ifstream source("ex949-input.txt");
    std::string word;

    std::string longest_word;

    while(source >> word)
    {
        if(word.size() > longest_word.size() 
            && word.find_first_of("gqyjp") == std::string::npos // descenders
            && word.find_first_of("ldfkbti") == std::string::npos) // ascenders

            longest_word = word;
    }

    std::cout << longest_word << std::endl;


    return EXIT_SUCCESS;
}