#include <iostream>

int txt_size() { return 1;}

int main()
{
    unsigned buf_size = 1024;

    int ia[buf_size]; // illegal, not a constant size value (according to C++ ISO)
    int ia2[txt_size()]; // illegal, not a constant size value 
    int ia3[4 * 7 - 14]; // legal
    //char st[11] = "fundamental"; // illegal, not enough space for '\0'


    return 0;
}