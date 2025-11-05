#include <iostream>
#include <vector>

int main()
{
    std::vector<int> empty_vec;

    empty_vec.front();
    empty_vec.back();
    empty_vec[0];
    empty_vec.at(0);

    return EXIT_FAILURE;
}