#include <iostream>

int func()
{
    static unsigned short cc = 0u;

    if (!cc)
    {
        ++cc;
        return 0;
    }
    
    for (size_t i = 0; i != cc; ++i)
        std::cout << i;
    std::cout << std::endl;
    ++cc;
    return 1;
}

int main()
{
    func();
    func();
    func();
    func();
    func();
    func();
    func();
    func();

}