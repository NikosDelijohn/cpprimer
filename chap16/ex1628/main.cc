#include <iostream>
#include "shared_ptr.hpp"

void my_deleter(void* p)
{
    delete static_cast<int*>(p);
}

int main()
{


    auto mysp = msp::shared_ptr<int>(new int(42));
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