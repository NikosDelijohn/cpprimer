#include <iostream>

struct X{
    
    X (int i, int j):
        base(i), 
        rem(base %j)
    {}
    // Error. Rem is initialized first. But base has not been yet initialized
    // The order is wrong!
    // int rem;
    // int base;
    int base, rem; // ok now!
};

int main()
{
    X var(5,4);
    std::cout<< var.rem << std::endl;
}