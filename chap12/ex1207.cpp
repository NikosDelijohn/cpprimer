#include <iostream>
#include <vector>
#include <memory>

std::shared_ptr<std::vector<int>> create_vector()
{
    return std::make_shared<std::vector<int>>();
}

// Passing by value copies the pointer
void fill_vector(std::shared_ptr<std::vector<int>> vec)
{
    int num;
    while(std::cin >> num)
        vec->push_back(num);
}

void print_vector(const std::shared_ptr<std::vector<int>>& vec)
{
    for (auto &elem: *vec)
        std::cout << elem << " " << std::ends;
    std::cout << std::endl; 
}

int main()
{

    std::shared_ptr<std::vector<int>> vec = create_vector();
    fill_vector(vec);
    print_vector(vec);
    
    return EXIT_SUCCESS;
}