#include <iostream>

void swap(int *ptr_a, int *ptr_b)
{
    int tmp = *ptr_a;
    *ptr_a = *ptr_b;
    *ptr_b = tmp; 
}

int main()
{
    int a = 1, b = 2;

    std::cout << a << " " << b << std::endl;
    swap(&a,&b);  
    std::cout << a << " " << b << std::endl;
}