#include <iostream>
#include <string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    double test_init1 = 0;
    double test_init2{0};
    double test_init3 = {0};
    // double test_init4(0); // not allowed!

};