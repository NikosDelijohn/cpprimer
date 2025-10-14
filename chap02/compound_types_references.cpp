#include <iostream>

// references also called lvalue references

int main()
{

    int ival = 1024;
    int &ref_val = ival;

    //int &ref_to_temp = 42; // wrong! cannot bind to temporary value 

    std::cout << ival << std::endl; // 1024
    ref_val = 2;
    std::cout << ival << std::endl; // 2

    int &ref_val2 = ref_val;
    ref_val2 = 3; 
    std::cout << ival << std::endl; // 3

    int i = ref_val2;
    i = 4;
    std::cout << ival << std::endl; // 3

    // ref to pointer
    int *p;
    int *&rp = p;
    
    rp = &ival; // p now points to ival
    std::cout << (*p == *rp) << std::endl; //expect 1

    // @@@@@@@@@@@@@@@@@@@@@ CONST @@@@@@@@@@@@@@@@@@@@@

    // the type of a reference must match the type of the object to which it refers to.
    // exception 1: initialize a reference to const from any expression that can be converted to the type of the reference.

    int num = 42;
    const int &r1 = num;

    num = num + 1;
    std::cout << "num=" << num << " r1=" <<r1 << std::endl;
    num = num + 1;
    std::cout << "num=" << num << " r1=" <<r1 << std::endl;

    //but this is not possible
    //r1 = r1 + 1;
    // Hence, in this way we create a READ-ONLY alias to the object. 
    // Use cases:
    // - When you want readonly behavior of an object through an alias
    // - Performance; Avoid copying 'large' objects:
    /*
        void printString(const std::string& s) {
            std::cout << s << "\n";
        }
            
        Here we pass by reference without allowing modification of the object
    */

    // double &refd = num; // wrong but:
    int num2 = 100;
    const double &refd = num2; // valid! <- a reference to const (refd) from any expression (num) that can be converted (int -> double) to the type of the reference (double).
    std::cout << refd << std::endl; 
    num2++;
    std::cout << num2 << " but ref is " << refd << std::endl;
    /* Internally here, due to type missmatch the compiler does the following 
    
    const double temp = dval;
    const double &refd = temp;
    
    So the linkage to an object is 'invisible' to the programmer. Here you have distinct object unlinked
    with the one you intended to link. This cannot be done for pointers though!
    */

    const int &ref_to_temp = 10; // this is valid however!

    return 0;
}