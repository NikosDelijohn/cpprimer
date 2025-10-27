#include <iostream>

void print(const int* var, size_t n)
{
    auto begin = var;
    auto end = begin + n;
    
    while(begin != end)
    {
        std::cout << *begin++ << " ";
    }

    std::cout << std::endl;
}

int main()
{   
    int i = 0;
    int j[2] = {0,1};
    print(&i, 1);
    print(j, 2);
}