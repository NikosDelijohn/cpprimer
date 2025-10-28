#include <iostream>

int sum(std::initializer_list<int> numbers)
{
    int sum = 0;

    for (const int &number: numbers)
        sum += number;

    return sum;

}

int main()
{

    std::cout << sum({1,2,3,4,5,6,7,8,9,10}) << std::endl; // 55

    return 0;
}