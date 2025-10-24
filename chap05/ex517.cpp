#include <iostream>
#include <vector>
using std::vector;

int main()
{
    vector<int> v1 = {0,1,1,7,4,5,6,7};
    vector<int> v2 = {0,1,1};

    const vector<int> &smaller = (v1.size() < v2.size()) ? v1 : v2;
    const vector<int> &larger = (smaller == v1) ? v2 : v1;

    bool is_prefix = true;

    for (decltype(smaller.size()) idx = 0u; idx < smaller.size(); ++idx)
    {
        if (smaller[idx] != larger[idx])
            is_prefix = false;
    }

    std::cout << std::boolalpha << is_prefix << std::endl;

    return 0;
}