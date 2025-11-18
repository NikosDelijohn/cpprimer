#include <iostream>
#include <memory>

void func(std::shared_ptr<int> ptr)
{

    std::cout << "Count is now : " << ptr.use_count() << std::endl;
}

int main()
{
    std::shared_ptr<int> sh_ptr = std::make_shared<int>(42);
    /* 
        Each shared pointer has an associated counter, the reference count.

        Whenever we COPY the counter is incremented. So when:
        + We use this pointer to initialize another shared_ptr
        + When we use it as the right-hand operand of an assignment
        + When we pass the smart pointer to a function by value
        + When we return the smart pointer by value.

        Inversely, the smart pointer's reference count is decremented when:
        - We assign a new value to the shared_ptr
        - The shared_ptr is destroyed
        - A local shared_ptr goes out of scope.

        When the counter reaches zero, the shared_ptr automatically frees the object
        that it manages.
    */
   
    auto p = sh_ptr; // p is another, independent shared_ptr that points to the same object as sh_ptr
    // hence, the reference count for the int object 42 is going up +1. Lets verify:
    std::cout << "Object " << *sh_ptr << " managed by " << p.use_count() << " pointers." << std::endl;
    
    func(sh_ptr); // pointer is passed by value, counter will increment!
    // However, the function simply uses the pointer. It is not returned
    // hence the counter will decrement when the function body exits and 
    // the argument gets out of scope!

    sh_ptr = std::make_shared<int>(41); // int 42's reference count is now decremented by one, 
    // int 41's reference count is now 1. Lets see now the count:
    std::cout << "Object " << *p << " managed by " << p.use_count() << " pointers." << std::endl; // can't use *sh_ptr to print, it now points elsewhere hence *p.

    // -------------------------------------- //
    // Not your typical raw pointer behavior! //
    // -------------------------------------- // 

    int some_random_int = 1996; // stack object !
    sh_ptr = std::make_shared<int>(some_random_int);
    // Does not do what you think. It may look misleading
    // like how raw pointers were used where the associated
    // objects address was bound to the pointer. But this is not the case.

    // make_shared invokes new to create a new, and completely different
    // variable which is initialized by `some_random_int` and lives in the heap!.
    //  The new variable is a distinct, separate copy of some_random_int. For instance, if 
    // I modify this value by:
    ++(*sh_ptr);

    // Then it has no effect on the some_random_int.
    std::cout << some_random_int << std::endl; // this prints 1996, not 1997!

    return EXIT_SUCCESS;
}