#include <iostream>

void ptrswap(int* &a, int* &b) // cleaner
{
    auto tmp = a;
    a = b; 
    b = tmp;
}

void ptrswap2(int **a, int **b)
{
    auto tmp = *a;
    *a = *b;
    *b = tmp;
}

int main()
{
    int a = 1, b = 42, *pa = &a, *pb = &b;

    std::cout << pa << " -> " << *pa << std::endl;
    std::cout << pb << " -> " << *pb << std::endl << " ---- " << std::endl; 
    ptrswap(pa,pb);
    std::cout << pa << " -> " << *pa << std::endl;
    std::cout << pb << " -> " << *pb << std::endl << " ---- " << std::endl;
    ptrswap2(&pa, &pb);
    std::cout << pa << " -> " << *pa << std::endl;
    std::cout << pb << " -> " << *pb << std::endl;

    return 0;
}