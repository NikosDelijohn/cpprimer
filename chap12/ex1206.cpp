#include <iostream>
#include <vector>

std::vector<int>* create_vector()
{
    return new std::vector<int>();
}

void fill_vector(std::vector<int>* vec)
{
    int num;
    while(std::cin >> num)
        vec->push_back(num);
}

void print_vector(std::vector<int>* vec)
{
    for (auto &elem: *vec)
        std::cout << elem << " " << std::ends;
    std::cout << std::endl; 
}

int main()
{
    
    std::vector<int> *vec = create_vector();
    fill_vector(vec);
    print_vector(vec);
    
    delete vec;

    return EXIT_SUCCESS;
}