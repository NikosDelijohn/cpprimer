#include <iostream>
#include <string>

int global_value = 10;

int foo () { return 123; }

constexpr int factorial(int val) // read line 64 and forward
{
    if (val == 0)
    {
        return 1;
    }
    if (val == 2 || val == 1)
    {
        return val;
    }
    
    return val * factorial(--val);
}

/* Invalid constexpr function which WILL raise compile-time errors!
   The reason here is that the function contains run-time actions!
*/
// constexpr int contains_runtime_action()
// {
//     int value = 0;
//     std::cin >> value; // constexpr.cpp:25:17: error: call to non-‘constexpr’ function 
//     return value;
// }

/* Invalid constexpr function. Return type is not of literal type! String is not a literal type*/
// constexpr
// std::string max(const int a, const int b)
// {
//     return (a>b) ? "a" : "b";
// }

int main()
{

/*
 __      __        _       _     _           
 \ \    / /       (_)     | |   | |          
  \ \  / /_ _ _ __ _  __ _| |__ | | ___  ___ 
   \ \/ / _` | '__| |/ _` | '_ \| |/ _ \/ __|
    \  / (_| | |  | | (_| | |_) | |  __/\__ \
     \/ \__,_|_|  |_|\__,_|_.__/|_|\___||___/
                                             
                                             
*/

    // constexpr imposes a top - level const to the type that it is applied. //

    int value = 10;
    // constexpr int *ptr = &value; // fails because value's address wont be preserved when its inside a function (although its main, same rules apply)
    
    // TOP LEVEL CONST
    constexpr int *ptr = &global_value; // ok. (imposes a top-level const) - its value can't change, the pointed to value can change
    *ptr = 55; // fine! 
    
    // TOP AND LOW LEVEL CONST
    constexpr const int *ptr2 = &global_value; // also ok. it imposes now a second const-int low level const. - its value can't change, the pointed to value can't change! 
    //*ptr2 = 66; // not fine!

    // constexpr versus const

    /* A */ constexpr const int *ptr3 = &global_value; // A.
    /* B */ const int *const ptr4 = &global_value; // B.
    
    // A and B are semantically equivalent!
    // They both impose: 
    //  - high-level const (pointer cannot change) 
    //  - low-level  const (pointee cannot change)
    // HOWEVER, (B) allows for ptr4 to be initialized at RUNTIME. So things like:

    int run_time_var = foo();
    const int *const ptr5 = &run_time_var; 
    // Are perfectly valid. 
    // On the other hand, (A) mandates that all values must be known at compile time and thus things like:
    //constexpr const int *ptr6 = &run_time_var; // are NOT valid. Compile-time evaluation is enforced!

    // ----------------------------------------------------------------- //

/*
  ______                _   _                 
 |  ____|              | | (_)                
 | |__ _   _ _ __   ___| |_ _  ___  _ __  ___ 
 |  __| | | | '_ \ / __| __| |/ _ \| '_ \/ __|
 | |  | |_| | | | | (__| |_| | (_) | | | \__ \
 |_|   \__,_|_| |_|\___|\__|_|\___/|_| |_|___/
                                              
                                              

*/ 
    
    // When the compiler can verify that at compile time that the arguments
    // and the return vals are known then the function is treated as a constexpr.

    // ** !! ** FUNCTION'S ARGUMENTS AND RETURN TYPE MUST BE LITERAL TYPES ** !! ** 
    //  - All scalar types: bool, all integer types (int, char, long, etc.), and all floating-point types (float, double, long double)
    //  - Pointers (including nullptr_t) even if pointee is NOT a literal type, because a pointer’s value (an address) can be known and represented at compile time.
    //  - References (to literal types)
    // 
    // vectors and strings are NOT literal types! 

    // The compiler will replace a call to a constexpr function with its resulting value!
    // In order to be able to expand the function immediately, constexpr functions are implicitly inline!
    //
    // In >=std++14 which permits multiple return statements if this function is called as factorial(5)
    // then the call will be replaced with the resulting value (120). If this function is called as
    // ...
    // int var;
    // std::cin >> var;
    // factorial(var);
    //
    // Then a normal function call will be issued because the value is known at runtime! However constexpr here
    // does not enforce compile-time evaluation for FUNCTIONS !!! 
    
    int var = factorial(5); // search in the .S file for 120! (compile with g++ -S constexpr.cpp -o out.S)
                            // -> movl	$120, -52(%rbp) # no call to factorial here.
    var = 22;
    // However here
    int var2; std::cout << "number?: "; std::cin >> var2;
    var2 = factorial(5);  
    /*
        movl	$5, %edi
        call	_Z9factoriali # a call is issued for the function!
        movl	%eax, -60(%rbp)
        movl	$0, %eax
    
    The code WILL compile, no compile-time restrictions for functions but
    the call will not be expanded and evaluated at compile time. It will be
    called normally.
    */

    // However, the compiler WILL complain when a constexpr function contains RUNTIME actions (lines 21-29)
    // Also, the compiler WILL complain when a constexpr function is used in the context where a const is 
    // required AND the call to the constexpr function does not return a const. Example:
    
    int arr[factorial(3)]; // OK, factorial 3 can be evaluated at compiletime!

    int fact_arg = 4;
    int arr2[factorial(fact_arg)];
    // Will fail with -pedantic-errors or strict standard compliance.
    // Although factorial is constexpr, fact_arg is runtime, so factorial(fact_arg) 
    // is evaluated at runtime. ISO C++ forbids variable length arrays, so this triggers a VLA error.
    // The “error” is thus a by-product of constexpr not being usable with runtime arguments.
    // However, g++ will allow VLAs if not expplicitly set to ISO compliance.

    return 0;
}