#include <iostream>
#include "shared_ptr2.hpp"

void my_deleter(int* p)
{
    delete p;
}

int main()
{


    auto mysp = msp::shared_ptr<int>(new int(42));
    std::cout << mysp.get_uses() << std::endl;
    {
        auto mysp2 = mysp;
        std::cout << mysp.get_uses() << std::endl;
        mysp = mysp2;
        std::cout << mysp.get_uses() << std::endl;

    }
    std::cout << mysp.get_uses() << std::endl;

    auto mysp_d = msp::shared_ptr<int>(new int(52), &my_deleter);

    return EXIT_SUCCESS;
}