#include <iostream>
#include "../help.hpp"

int main()
{
    unsigned char q = 113U; //0111_0001
    
    // unsigned char promoted to int
    auto res = ~q << 6; // ~ > << precedence! hence first: 1111_1111_1111_1111_1111_1111_1000_1110
                        //                           then: 1111_1111_1111_1111_1110_0011_1000_0000
    print_bits(q);    
    print_bits(res); // 1111_1111_1111_1111_1110_0011_1000_0000 

}