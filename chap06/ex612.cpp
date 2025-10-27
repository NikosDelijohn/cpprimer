#include <iostream>

void swap(int &ref_a, int &ref_b)
{
    int tmp = ref_a;
    ref_a = ref_b;
    ref_b = tmp; 
}

void swap2(int &ref_a, int &ref_b) // no 3rd variable used.
{
    ref_a = ref_a ^ ref_b;  // a xor b = c, ref_a = c
    ref_b = ref_a ^ ref_b;  // c xor b = a, ref_b = a
    ref_a = ref_a ^ ref_b;  // c xor a = b, ref_a = c (lhs) ref_b = a (lhs)
}

int main()
{
    int a = 1, b = 2;

    std::cout << a << " " << b << std::endl;
    swap(a,b);  
    std::cout << a << " " << b << std::endl;
    swap(a,b);  
    std::cout << a << " " << b << std::endl;    
}