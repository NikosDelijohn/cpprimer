#include <iostream>
#include <map>
#include <functional>
#include <string>

int b_and(int a, int b) { return a & b; }

struct b_or
{
    int operator()(int a, int b) { return a | b; }
};

auto b_xor = [](int a, int b) -> int 
             {
                return a ^ b;
             };

int b_lsh(int a, int b) { return a << b;}
int b_rsh(int a, int b) { return a >> b;}

struct b_not // this needs to match the same call signature...unused extra parameter.
{
    int operator()(int a, int) { return ~a;}
};

int main()
{
    std::map<std::string, std::function<int(int, int)>> bitops\
    {
        {"&", std::function<int(int,int)>(b_and)},
        {"|", std::function<int(int,int)>(b_or())},
        {"+", std::function<int(int,int)>(b_xor)},
        {"<", std::function<int(int,int)>(b_lsh)},
        {">", std::function<int(int,int)>(b_rsh)},
        {"!", std::function<int(int,int)>(b_not())}
    };

    std::cout << "2 AND 1 = " << bitops["&"](2,1) << std::endl;
    std::cout << "9 XOR 6 = " << bitops["+"](9,6) << std::endl;

    return EXIT_SUCCESS;
}