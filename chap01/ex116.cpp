#include <iostream>

int main()
{

    int sum = 0;
    int number; 

    while (std::cin >> number)
        sum+=number;

    std::cout << "Sum: " << sum << std::endl;
    
    return 0;
}