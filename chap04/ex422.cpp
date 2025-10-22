#include <iostream>
#include <string>

int main()
{
    int grade;
    std::cin >> grade;

    const char *result = (grade > 90) ? "high pass"
                 : (grade > 75) ? "pass"
                 : (grade > 60) ? "low pass" : "fail";

    std::cout << "your result is: " << *result << std::endl;

    std::string result2;
    if (grade > 90)
    {
        result2 = "high pass";
    }
    else if ( grade > 75)
    {
        result = "pass";
    }
    else if ( grade > 60)
    {
        result = "low pass";
    }
    else 
    {
        result = "fail";
    }
    std::cout << "your result is: " << result2 << std::endl;
            
    
    return 0;
}