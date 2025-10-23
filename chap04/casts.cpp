#include <iostream>

int main()
{
    /*
    static_cast: any well-defined conversion besides those involving low-level consts!
                 able to perform conversions that the compiler won't do on itself (eg. void ptr -> type ptr)
    */
    double dval = 3.14;
    void *vp = &dval; //ok but we cannot dereference
    
    //std::cout << vp << " -> " << *vp << std::endl; // wrong, void* is not a pointer-to-object type
    // but 
    double *dvalp = static_cast<double*>(vp);
    std::cout << dvalp << " -> " << *dvalp << std::endl;

    /*
    const_cast: changes only a low-level const

    if the object was originally not const, then turned const and now const is removed, thats legal
    if we use const_cast to remove an original const and then write to that object, we get undefined behavior

    cannot be used to cast a type to another. its just used for changing constness!

    its most useful in the context of overloaded functions
    */

    int val = 42;
    const int *pval = &val;
    //int *noconstval = pval; // wrong, pval is low level const ! but...
    int *noconstval = const_cast<int *>(pval);  // works.
    *noconstval = 1; // ok but UNDEFINED behavior!!
    std::cout << val << std::endl; // !!!


    /*
    reinterpret_cast: asks the compiler to reinterpret the raw bit values of the operand
    */

    unsigned int ipval = 0x7E; // ~ tilde symbol ascii hex val
    unsigned int *ip = &ipval;
    char *pc = reinterpret_cast<char*>(ip);
    
    std::cout << "There's no place like " << *pc << std::endl;

    // but this is useless for such operations since we can simply do:
    char p = 0x7E;
    std::cout << p << std::endl;

    // however, where it shines is to have a view and possibly manipulate (!) a memory region
    struct net_packet
    {
        int id;
        int value;
    };

    net_packet packet{15,16};
    unsigned char* rawbits = reinterpret_cast<unsigned char*>(&packet);
    // you can only access an object through a pointer of its own type (or a few exceptions).
    // These exceptions are for (i) char, (ii) unsigned char, and (iii) std::byte.
    for (size_t i = 0u; i < sizeof(packet); ++i)
    {
        std::cout << std::hex << (int)rawbits[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}