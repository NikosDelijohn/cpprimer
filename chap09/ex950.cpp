#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;

int main()
{
    vector<string> svec = {"1","2","3","4","5","6","7"};

    int sum = 0;
    for (string &elem: svec)
        sum += std::stoi(elem);
    
    std::cout << sum << std::endl;

    // -------------------------- //

    float fsum = 0.0;
    vector<string> sfloat= {"3.14","3.156", "3.44", "5.55", "5.55"};
    for (string &elem: sfloat)
        fsum += std::stof(elem);
    
    std::cout << fsum << std::endl;

    return EXIT_SUCCESS;
}