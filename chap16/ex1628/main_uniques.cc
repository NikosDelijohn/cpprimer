#include <iostream>
#include "unique_ptr.hpp"

void my_deleter(int* p)
{
    delete p;
}

msp::unique_ptr<int> make_int()
{
    msp::unique_ptr<int> p(new int(42));
    return p;   // moved (or elided)
}

int main()
{

    int factor = 2;

    auto mysp = msp::unique_ptr<int, void (*)(int*)>(new int(42), my_deleter);
    std::cout << *mysp << std::endl;

    mysp = nullptr;


    auto mysp2 = msp::unique_ptr<int, void (*)(int*)>(
        new int(43),
        [](int* p) 
        {
            delete p;
        }
    );
    std::cout << *mysp2 << std::endl;


    auto capturing_lambda_deleter = [factor](int* var) -> void
    {
        std::cout << factor << std::endl;
        delete(var);
    };

    msp::unique_ptr<int, decltype(capturing_lambda_deleter)> mysp3 {new int(44), capturing_lambda_deleter};
    std::cout << *mysp3 << std::endl;

    auto mysp4 = make_int();
    std::cout << *mysp4 << std::endl;

    int *ptr_new = new int(55);
    mysp.reset(ptr_new);
    std::cout << *mysp << std::endl;

    mysp.release(); 
    std::cout << std::boolalpha << (mysp.get() == nullptr) << std::endl;

    return EXIT_SUCCESS;
}