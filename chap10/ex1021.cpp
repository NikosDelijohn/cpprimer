#include <iostream>

int main()
{  
    int i_val = 5;

    auto is_zero = [&i_val]() -> bool
    {
        if (i_val == 0)
            return true;
        else
        {
            --i_val;
            return false;
        }
    };

    while (i_val)
    {
        std::cout << "ival: " << i_val << std::endl; 
        is_zero();
    }

    std::cout << std::boolalpha << is_zero() << std::endl;
    
    return EXIT_SUCCESS;
}