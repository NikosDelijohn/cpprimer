#include <iostream>


class numbered
{
public:
    numbered() : sn{++seed} {}
    numbered(const numbered &other): sn(++seed){}

    size_t sn;

private:
    static size_t seed;
};
size_t numbered::seed = 0u;

void f (const numbered &s)
{
    std::cout << s.sn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a); f(b); f(c);
}