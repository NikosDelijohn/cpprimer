#include <iostream>
#include <vector>
#include <cassert>
using std::vector;

int main()
{
    vector<int> vals = {1};
    auto a = vals.begin();
    auto b = vals.end() - 1;

    assert(a == b);

    vals.erase(a, b); // NO removal - [a,b) -> [a,a)

    for (auto &elem: vals)
        std::cout << elem << std::endl;

    // moving one-past the last
    ++a;
    ++b;
    vals.erase(a,b); // UB !!

    for (auto &elem: vals)
        std::cout << elem << std::endl;

    return EXIT_SUCCESS;

}