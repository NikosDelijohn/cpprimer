#include <iostream>
#include "shared_ptr3.hpp"

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

    auto my_made_sp_d = msp::make_shared<double>(5.2);
    std::cout << *my_made_sp_d << std::endl;

    return EXIT_SUCCESS;
}