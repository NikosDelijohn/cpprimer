#include "vec.hpp"

struct dummy_aggr
{
    int x,y,z;

    dummy_aggr(int a, int b, int c): x(a), y(b), z(c){}
};

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

    
    vec<dummy_aggr> my_vector2;
    my_vector2.emplace_back(1,1,1);
    my_vector2.emplace_back(2,2,2);
    my_vector2.emplace_back(3,3,3);

    for (auto &elem: my_vector2)
        std::cout << elem.x << ", " << elem.y << ", " << elem.z << std::endl;

    return EXIT_SUCCESS;
}