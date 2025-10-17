#include <iostream>
#include <vector>

using std::vector;

int main()
{
    /*
    There are four syntactic forms of initialization:
    
    copy initialization   : type var = val; doesn't require a constructor
    
    direct initialization : type var(val); requires constructor

    list initializations  : type var = {val}; <- this is a copy-list initialization
                            type var{val} 
    
        also prevents narrowing conversions (e.g., double -> int)
        do not require constructor
    */

    int intval1 = 1; // copy init
    int intval2(1); // direct init
    int intval3 = {1}; // copy-list init 
    int intval4{1}; // list init

    // Not necessarily all are allowed for all types.

    // vector<int>(1,2,3,4); // this is not allowed. no such constructor exists -but-
    vector<int>(4,1); // this is allowed because such a constructor exists. it adds 4 elements initialized to 1 -or even-
    vector<int>(4); // also ok. 4 elements which are Value Initialized
    vector<int> {1,2,3,4}; // this is allowed.
    
    /*
    Then we have value initialization and default initialization
    */

    struct example {
        int x;
        int y;
    };

    // Default initialization!
    example a;
    std::cout << a.x << " " << a.y << std::endl; // these have garbage!

    // Value initialization
    example b{}, c = {};
    std::cout << b.x << " " << b.y << std::endl; // these are 0!
    std::cout << c.x << " " << c.y << std::endl; // similarly.

    return 0;
}