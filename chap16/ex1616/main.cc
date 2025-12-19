#include "vec.hpp"

int main()
{
    vec<int> my_vector;
    my_vector.push_back(1);
    my_vector.push_back(2);
    my_vector.push_back(3);

    for (auto &elem: my_vector)
        std::cout << elem << std::endl;

    my_vector.clear();
    
    for (auto &elem: my_vector)
        std::cout << elem << std::endl;

    return EXIT_SUCCESS;
}