#include <iostream>

// decltype, when applied to variable that is const (top-level)
// it returns the const. It does not ommit it 

int main()
{
    const int ci = 42, &cj = ci;

    decltype(ci) x = 0; // x is const int. -but-
    auto x2 = ci; // x2 is int ! top level const is ignored here

    decltype(cj) y = x; // y is const int &. -but-
    auto y2 = cj; // y2 is int ! top level const is ignored here

    int value = 1;
    int &ref_val = value;

    //decltype (ref_val) a_ref; // wrong, a_ref is int &. -but-
    auto a_ref = ref_val; // ref_val is int.

    // Rules for decltype
    /*
    If the expression is an unparenthesized variable name like 'var', decltype (var) returns the declared type, including top-level const
    If the expression is any other expression that is an lvalue, decltype(expr) it returns a reference to the declared type.
    */

    // VS AUTO

    int arr[] = {1,2,3,4};

    auto auto_arr(arr); // this is int* ! IT DEDUCES the type
    decltype(arr) decl_arr; // this is int[4] ! IT returns the EXACTLY DECLARED type
    decltype((arr)) decl_ref_arr = arr; // this is int &[4] ! A Reference to the declared type and thus it must be initialized

    return 0;
}