#include <iostream>

class Base
{
public:
    int& get(){return ival;}
    
private:
    int ival = 5;
};

int main()
{
    Base b;
    auto &ref = b.get();
    std::cout << b.get() << std::endl;
    ref = 20;
    std::cout << b.get() << std::endl;
}