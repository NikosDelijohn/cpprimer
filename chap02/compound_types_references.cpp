#include <iostream>
#include <string>
#include <utility>

// references also called lvalue references
// rvalue references are used to bind to temporaries and enable move semantics

int main()
{
    std::cout << "===== LVALUE REFERENCES =====" << std::endl;

    int ival = 1024;
    int &ref_val = ival;

    // int &ref_to_temp = 42; // wrong! cannot bind to temporary value

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
    int *&rp = p; // Note: `int &* rp` is illegal syntax.

    rp = &ival; // p now points to ival
    std::cout << (*p == *rp) << std::endl; // expect 1

    // @@@@@@@@@@@@@@@@@@@@@ CONST @@@@@@@@@@@@@@@@@@@@@

    // the type of a reference must match the type of the object to which it refers.
    // exception 1: initialize a reference to const from any expression that can be converted to the type of the reference.

    int num = 42;
    const int &r1 = num;

    num = num + 1;
    std::cout << "num=" << num << " r1=" << r1 << std::endl;
    num = num + 1;
    std::cout << "num=" << num << " r1=" << r1 << std::endl;

    // but this is not possible
    // r1 = r1 + 1;
    // Hence, in this way we create a READ-ONLY alias to the object.
    // Use cases:
    // - When you want readonly behavior of an object through an alias
    // - Performance: Avoid copying 'large' objects
    /*
        void printString(const std::string& s) {
            std::cout << s << "\n";
        }

        Here we pass by reference without allowing modification of the object
    */

    // double &refd = num; // wrong! Cannot directly bind reference to expression requiring type conversion but:
    int num2 = 100;
    const double &refd = num2; // valid! reference to const binding to temporary of converted type
    std::cout << refd << std::endl;
    num2++;
    std::cout << num2 << " but ref is " << refd << std::endl;
    /* Internally here, due to type mismatch the compiler does the following

        const double temp = dval;
        const double &refd = temp;

       So the linkage to an object is 'invisible' to the programmer. Here you have distinct object
       unlinked with the one you intended to link. This CANNOT be done for pointers!
    */

    const int &ref_to_temp = 10; // valid! binds to temporary


    std::cout << "\n===== RVALUE REFERENCES =====" << std::endl;

    // rvalue references bind to temporaries and allow "stealing" resources (move semantics)

    // 1) Bind rvalue reference to a literal (temporary)
    int &&rr1 = 42;   // valid: 42 is a temporary (prvalue)
    std::cout << "rr1=" << rr1 << std::endl;

    rr1 = 100;        // modifies the temporary bound to rr1
    std::cout << "rr1 now=" << rr1 << std::endl;

    // Note: rr1 itself is a named variable -> it is an lvalue, even though its type is int&&

    // 2) Bind to a temporary created by an expression
    int &&rr2 = ival + 10; // valid: result of arithmetic is a temporary
    std::cout << "rr2=" << rr2 << std::endl;

    // 3) Rvalue references cannot bind to lvalues directly
    // int &&rr3 = ival; // ERROR: ival is an lvalue

    // 4) std::move converts an lvalue to an xvalue (treated as an rvalue)
    int &&rr4 = std::move(ival); // valid: ival is now "movable-from"
    std::cout << "rr4 (moved from ival)=" << rr4 << std::endl;

    // 5) static_cast can also cast an lvalue to an rvalue reference
    int lvalue = 242;
    int &&rr5 = static_cast<int&&>(lvalue); // equivalent to std::move(lvalue)

    // After moving, ival still exists but its value is conceptually unspecified
    // For built-in types like int, it is still usable
    std::cout << "ival after move (still defined for ints): " << ival << std::endl;

    // 6) Move semantics with user-defined types
    std::string a = "hello";
    std::string b = std::move(a); // resources of 'a' are moved to 'b'

    // After move:
    // - b now owns the original memory of 'a'
    // - a is in a valid but unspecified state (still destructible and assignable)
    std::cout << "b=" << b << std::endl;
    std::cout << "a after move=" << a << std::endl;

    // Summary:
    // - Named rvalue references are lvalues themselves
    // - Rvalue references allow efficient resource transfer
    // - They are used for:
    //    * Move constructors / move assignment
    //    * Avoiding unnecessary copies
    //    * Perfect forwarding in templates

    return 0;
}

/*

    +-------------------------------------------+---------------------------+
    | Expression Type                           | Value Category            |
    +-------------------------------------------+---------------------------+
    | Named variable (int x;)                   | lvalue                    |
    | Dereference (*p)                          | lvalue                    |
    | Subscript (a[i])                          | lvalue                    |
    | String literal ("hi")                     | lvalue                    |
    | Function returning T&                     | lvalue                    |
    | Assignment result (a = b)                 | lvalue                    |
    | Prefix ++/-- (++i, --i)                   | lvalue                    |
    +-------------------------------------------+---------------------------+
    | Literal (42, 3.14)                        | rvalue (prvalue)          |
    | Temporary object (std::string("hi"))      | rvalue (prvalue)          |
    | Function returning T (by value)           | rvalue (prvalue)          |
    | Arithmetic result (x + y)                 | rvalue (prvalue)          |
    | Postfix ++/-- (i++, i--)                  | rvalue (prvalue)          |
    | Cast creating a temporary (T(…))          | rvalue (prvalue)          |
    +-------------------------------------------+---------------------------+
    | std::move(x)                              | rvalue (xvalue)           |
    | static_cast<T&&>(x)                       | rvalue (xvalue)           |
    +-------------------------------------------+---------------------------+

                    lvalues: have identity, addressable, persist beyond the expression.
    prvalues (pure rvalues): temporary values with no identity.
  xvalues (expiring values): still have identity but treated like rvalues (e.g., std::move(x))

*/