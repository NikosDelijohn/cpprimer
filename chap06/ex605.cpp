#include <iostream>

double abs(const double par)
{
    if (par >= 0)
    {
        return par;
    }
    else
    {
        return par + (-2.0 * par);
    }
}

int main()
{
    double value; 
    std::cin >> value;

    std::cout << "|" << value << "| = " << abs(value) << std::endl;
}