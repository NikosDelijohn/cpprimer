#include <iostream>

int get_size(int val) { return val; }

int main()
{
    int someval;
    std::cin >> someval;

    int sz = get_size(someval);
    
    while (sz <= 0)
    {
        sz = get_size(someval);
    }
}