#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    
    std::string concatenated;

    for (int i = 1; i < argc; ++i)
    {
        concatenated += std::string(argv[i]) + " ";
    }

    std::cout << concatenated << std::endl;

    return 0;
}