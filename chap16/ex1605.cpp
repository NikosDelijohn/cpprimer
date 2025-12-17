#include <iostream>

template<typename T, unsigned N>
void print(T (&arr)[N])
{
    for(auto &elem: arr)
        std::cout << elem << std::endl;
}

int main()
{

    int arr[10] = {1,2,3,4,5};
    double darr[3] = {3.14, 2.718, 1.618};
    char cstr[] = "Hello"; // reminder: NULL terminator added automatically here.
       
    print(arr);
    print(darr);
    print(cstr);

    return EXIT_SUCCESS;
}