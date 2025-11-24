#include <iostream>
#include <new>
#include <cstring>

int main()
{
    char *cc = new char[2];

    while(std::cin >> cc)
    {
        std::cout << cc << " - len:"<< std::strlen(cc) << std::endl;
    }
    delete [] cc;

    return EXIT_SUCCESS;
}