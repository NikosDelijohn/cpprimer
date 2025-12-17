#include "a.hpp"

int main()
{
    A<int> a;
    a.test();

    A<float> af;
    af.test();

    A<double> ad;
    ad.test();

    // This will cause a linker error!
    A<char> ac;
    ac.test();
}