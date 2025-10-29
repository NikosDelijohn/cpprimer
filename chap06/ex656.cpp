#include <iostream>
#include <vector>

using F = int(int, int);

int iadd(int a, int b) {return a + b;}
int isub(int a, int b) {return a - b;}
int imul(int a, int b) {return a * b;}
int idiv(int a, int b) {return a / b;}

int main()
{
    std::vector<F *>vec; // or ...
    std::vector<int (*)(int,int)> equivalent_vec;

    vec = {iadd, isub, imul, idiv};
    equivalent_vec = {&iadd, &isub, &imul, &idiv};

    std::cout << vec[0](5, 5) << std::endl;
    std::cout << vec[1](5, 5) << std::endl;
    std::cout << vec[2](5, 5) << std::endl;
    std::cout << vec[3](5, 5) << std::endl;
}