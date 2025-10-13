#include <iostream>

int main()
{
    std::cout << "/*";  // OK
    std::cout << "*/"; // OK
    //std::cout << /* "*/" */;
    std::cout << /* "*/" */"; // NOW OK
    std::cout << /* "*/" /* "/*" */; // OK

    return 0;
}