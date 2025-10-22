#include <iostream>

int main()
{
    char cval; 
    float fval; 
    int ival;
    double dval;
    unsigned int ui;

    cval = 'a' + 3; // char 'a' is promoted to int. the + result is narrowed to char (may have unexpected results)
    fval = ui - ival * 1.0; // * happens first. ival converted to double (literals with no f suffix are double)
                            // ui is unsigned int. the * result is double. this is machine dependant now
                            // since ui fits in a double, ui is converted to double. then the result is narrowed to float
    dval = ui * fval; // ui is converted to float. float is then widened to double.
    return 0;
}