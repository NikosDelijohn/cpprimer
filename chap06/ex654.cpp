#include <iostream>
#include <vector>

using F = int(int, int);

int main()
{
    std::vector<F *>vec; // or ...
    std::vector<int (*)(int,int)> equivalent_vec;
}