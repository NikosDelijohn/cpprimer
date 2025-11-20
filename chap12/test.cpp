#include <memory>
#include <iostream>

int main()
{
    int *ip = new int(42);
    {
        std::unique_ptr<int> sp(ip);
        std::cout << *sp << std::endl;
        *ip = 423;
        std::cout << *sp << std::endl;
    }   
    
    std::cout << *ip << std::endl;
    delete ip;
}