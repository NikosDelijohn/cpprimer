#include <iostream>
#include <string>

std::string global_str;
int global_int;

int main()
{
    int local_int;
    std::string local_str;

    // undefined initial val
    std::cout << local_int << " " << local_str  << std::endl;

    // defined, set to 0 initial val
    std::cout << global_int << " " << global_str << std::endl;
    
    return 0;
}