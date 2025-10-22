#include <iostream>
#include <vector>
using std::vector;

int main()
{
    // Both return lvalues 
    // Postfix increments or decrements the operand but yields a copy of the UNCHANGED original value
    // Prefix increments or decrements the operand and yields the object itself 

    int i = 0, j;

    j = ++i; // i = 1 and j = 1. prefix yields the incremented value!

    std::cout << "j = " << j << " i = " << i << std::endl;

    j = i++; // i = 2 and j = 1. postfix yields the unincremented value;

    std::cout << "j = " << j << " i = " << i << std::endl;


    // precedence scenario with postfix

    vector<int> vals {1,2,3,4,5,6,7,8,-1,4,5,6};
    vector<int>::iterator beg = vals.begin();
    
    while (beg != vals.end() && *beg >=0)
        std::cout << *beg++ << ' ';
    std::cout << std::endl; 
    
    beg = vals.begin();
    std::cout << ++*beg << std::endl; // DEREFERENCE first, PRE INCREMENT second
    std::cout << *++beg << std::endl; // PRE INCREMENT first, DEREFERENCE second
    std::cout << *beg++ << std::endl; // POST INCREMENT first, DEREFERENCE second

    // this will print all numbers up to the first negative number!
    // *beg++ is actually *(beg++) because ++ has higher precedence than the dereference operator *
    // hence the iterator moves up one position and returns the original unchanged value which is then
    // dereferenced and printed out to stdout!

    return 0;
}