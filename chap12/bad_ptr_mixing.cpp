#include <memory>

void process(std::shared_ptr<int> ptr) 
{ 
    /* Pass by value */

    /* Do something with the ptr */
    
}/* Destroy & Free when body ends. */

int main() 
{

    auto p  = new int();
    auto sp = std::make_shared<int>();

    process(sp);
    // Fine. Pass by value. SP is copied, use_count incremented and decremented afterwards.

    // shared_ptr ctor is explicit. Cannot use raw ptr to create a shared_ptr like this 
    //process(new int());
    //process(p);

    //However, here's something dangerous:
    // process(std::shared_ptr<int>(p)); // This compiles!

    /*
    This will compile. However, here's the problem.
    A temporary SP is created at call time and takes ownership of a raw! pointer p.
    After the process terminates, the temporary SP is deleted and thus, its point-to 
    memory is freed. 

    Pointer p is now dangling! Thus dereferencing pointer or using it past this point is UB 
    */

    // Equivalently dangerous:
    // process(std::shared_ptr<int>(sp.get())); // This compiles!
    
    /*
    This will also compile. But here is what really happens:

    sp.get() returns the raw pointer that 'sp' owns.

    Then we create a NEW (temporary) shared_ptr that ALSO thinks it owns
    the same raw pointer — but with a completely separate control block.

    This does NOT transfer ownership from 'sp'. 
    Both shared_ptr objects now think they own the pointer independently!

    Sequence:

    1. temp shared_ptr<int> is created with raw pointer sp.get().
    2. temp shared_ptr<int> is passed by value to process().
    3. When process() ends, the temp shared_ptr is destroyed → it deletes the pointer.
    4. Now 'sp' is dangling because the memory it manages was already deleted.
    5. When 'sp' is destroyed later, it tries to delete the pointer again → DOUBLE DELETE (undefined behavior).

    So the bug is: two independent shared_ptr objects own the same raw pointer.
    That's why this call is extremely dangerous.
    */

    // Similar to what happens here:
    auto sp2 = std::make_shared<int>();
    auto p2 = sp2.get();
    delete p2; // this will leave sp2 dangling! So when sp2 is deleted we will have double free() error! DANGEROUS!
    

    return 0;
}