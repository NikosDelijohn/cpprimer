#include <iostream>
#include <string>

void find_numerics(const std::string &source)
{
    std::string::size_type pos = 0;
    while((pos = source.find_first_of("0123456789", pos)) != std::string::npos )
    {
        std::cout << "Number at index: " << pos << ", number is " <<source[pos] << std::endl;
        ++pos; 
    }

    pos = 0;
    while((pos = source.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", pos))!= std::string::npos)
    {
        std::cout << "Number at index: " << pos << ", number is " <<source[pos] << std::endl;
        ++pos; 
    }
}

int main()
{
    find_numerics("ab2c3d7R4E6");

    return EXIT_SUCCESS;
}