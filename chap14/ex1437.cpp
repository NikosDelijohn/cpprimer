#include <iostream>
#include <algorithm>
#include <vector>

class is_equal_to
{
public:
    is_equal_to(int value): val(value){};
    bool operator()(const int &other) { return val == other; }

private:
    int val;
};

int main()
{
    std::vector<int> ivec {1,1,2,2,3,4,5,5};
    int old_val;
    std::cout << "Value to replace?: ";
    std::cin  >> old_val;

    int new_val;
    std::cout << "New value for '" << old_val << "' is: ";
    std::cin >> new_val;

    is_equal_to eq(old_val);

    std::replace_if(ivec.begin(), ivec.end(), eq, new_val);

    for(auto &elem: ivec)
        std::cout << elem << " " << std::ends;
    std::cout << std::endl;
}