#include <iostream>

class int_ITE
{
public:
    int operator()(bool condition, int True, int False)
    {
        return condition ? True : False;
    }

};

int main()
{
    int_ITE ITE;

    std::cout << ITE(true, 2, 1) << std::endl;
    std::cout << ITE(false, 2, 1) << std::endl;

    return EXIT_SUCCESS;
}