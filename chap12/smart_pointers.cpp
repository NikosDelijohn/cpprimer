#include <iostream>
#include <memory>

void func(std::shared_ptr<int> ptr)
{

    std::cout << "\t\t In func(): Count is now : " << ptr.use_count() << std::endl;
}

int main()
{

/*
      _                        _           _        
     | |                      | |         | |       
  ___| |__   __ _ _ __ ___  __| |    _ __ | |_ _ __ 
 / __| '_ \ / _` | '__/ _ \/ _` |   | '_ \| __| '__|
 \__ \ | | | (_| | | |  __/ (_| |   | |_) | |_| |   
 |___/_| |_|\__,_|_|  \___|\__,_|   | .__/ \__|_|   
                              ______| |             
                             |______|_|             
*/

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
    std::cout << "use_count() Showcase:\n";

    std::shared_ptr<int> sh_ptr = std::make_shared<int>(42);
    std::cout << "\tsh_ptr initialized to 42: Object " << *sh_ptr << " managed by " << sh_ptr.use_count() << " pointers." << std::endl;
    auto p = sh_ptr; // p is another, independent shared_ptr that points to the same object as sh_ptr
    std::cout << "\tp = sh_ptr: Object " << *sh_ptr << " managed by " << sh_ptr.use_count() << " pointers." << std::endl;

    // hence, the reference count for the 
    // int object 42 is going up +1. Lets verify:
    std::cout << "\tBefore going to func(): Object " << *sh_ptr << " managed by " << p.use_count() << " pointers." << std::endl;
    
    func(sh_ptr); // pointer is passed by value, counter will increment!
    // However, the function simply uses the pointer. It is not returned
    // hence the counter will decrement when the function body exits and 
    // the argument gets out of scope! So its +1 -1

    std::cout << "\tAfter going to func(): Object " << *sh_ptr << " managed by " << p.use_count() << " pointers." << std::endl;

    sh_ptr = std::make_shared<int>(41); // int 42's reference count is now decremented by one, 
    // int 41's reference count is now 1. Lets see now the count:
    std::cout << "\tSh_ptr now points elsewhere: Object " << *p << " managed by " << p.use_count() << " pointers." << std::endl; // can't use *sh_ptr to print, it now points elsewhere hence *p.

    std::cout <<"reset() Case:\n";
    auto p2 = p;
    p.reset(); // makes pointer null. if use_count is 1 the pointee is also destroyed. Use count now was 2, so now it will become 1.
    std::cout << *p2 << std::endl; // Underlying object still exists! Expect 42
    
    std::cout << "reset(q) Case:\n";
    p2.reset(new int(42)); // This reset will free the pointee because use_count will become zero
                           // but will not make p2 null. instead it binds it to a new object 42. 
    std::cout << "\tp2 now points to " << *p2 << std::endl;

    // DO NOT DO e.g,:

    // p2.reset(sh_ptr.get());
    // This will compile, however here we do not use copy ctor to update accordingly the
    // control block for the shared object (pointee). Two independent shared pointers 
    // manage the same pointer. When they get deleted, we will have a double free case.
    
    // -------------------------------------- //
    // Not your typical raw pointer behavior! //
    // -------------------------------------- // 
    
    std::cout <<"Smart ptr relationship with initialization variable: NONE!\n";
    int some_random_int = 1996; // stack object !
    sh_ptr = std::make_shared<int>(some_random_int);
    std::cout <<"\t initialized sh_ptr with some_random_int = " << some_random_int << " - " << "*sh_ptr = " << *sh_ptr << "\n";

    // Does not do what you think. It may look misleading
    // like how raw pointers were used where the associated
    // objects address was bound to the pointer. But this is not the case.

    // make_shared invokes new to create a new, and completely different
    // variable which is initialized by `some_random_int` and lives in the heap!.
    //  The new variable is a distinct, separate copy of some_random_int. For instance, if 
    // I modify this value by:
    ++(*sh_ptr);
    // Then it has NO effect on the some_random_int.
    std::cout <<"\t After ++(*sh_ptr): some_random_int = " << some_random_int << " - " << "*sh_ptr = " << *sh_ptr << "\n";

    std::cout << " ---------------------------- \n";
/*
              _                            _        
             (_)                          | |       
  _   _ _ __  _  __ _ _   _  ___     _ __ | |_ _ __ 
 | | | | '_ \| |/ _` | | | |/ _ \   | '_ \| __| '__|
 | |_| | | | | | (_| | |_| |  __/   | |_) | |_| |   
  \__,_|_| |_|_|\__, |\__,_|\___|   | .__/ \__|_|   
                   | |        ______| |             
                   |_|       |______|_|             
*/

    /*
    A unique_ptr OWNS the object to which it points. Only one unique_ptr at a time can point to a given object.
    The object to which unique_ptr points is destroyed when the unique_ptr is destroyed.
    */

    std::unique_ptr<int> uptr = std::make_unique<int>(24); // std++14 introduced this
    std::unique_ptr<int> another_uptr(new int(42)); // another way

    // Cannot copy!
    //auto uptr2 = uptr; // wrong!
    
    auto uptr2 = std::move(uptr); // can move though, uptr is nullptr now
    std::cout <<"After move uptr -> uptr2: uptr2 = " << *uptr2 << " and uptr == nullptr is " << std::boolalpha << (uptr == nullptr) << std::endl;

    // another way
    std::unique_ptr<int> uptr3(uptr2.release());

    // release relinquishes ownership of the pointee and makes the pointer null. it returns the raw pointer
    // thus, we initialize a new unique pointer (uptr3) to the now not owned raw pointer returned by release.

    std::cout << "After uptr3(uptr2.release()): uptr2 == nullptr is " << std::boolalpha << (uptr2 == nullptr)
              << " and now *uptr3 = " << *uptr3 << std::endl;

    uptr3.reset(); // makes uptr3 null and deletes the pointee. unless we provide a new raw ptr as an argument
    // so .reset(new int(42)) deletes the pointee and makes unique_ptr point to the new object.

    // IMPORTANT NOTE: .release() DOES NOT DELETE the resource. It simply relinquishes control. So its an 
    // error to write ptr.release() when we intend to do ptr.reset() !!! -> Memory leak

/*
                     _              _        
                    | |            | |       
 __      _____  __ _| | __    _ __ | |_ _ __ 
 \ \ /\ / / _ \/ _` | |/ /   | '_ \| __| '__|
  \ V  V /  __/ (_| |   <    | |_) | |_| |   
   \_/\_/ \___|\__,_|_|\_\   | .__/ \__|_|   
                       ______| |             
                      |______|_|             
*/

    /*
    A weak_ptr does not control the lifetime of the object to which it points. A weak_ptr points to an object that is managed
    by a shared_ptr. Once the last shared_ptr pointing to the object goes away, the object itself will be deleted even if 
    there are weak_ptrs still pointing to it. 
    */

    std::shared_ptr<int> shared_ptr = std::make_shared<int>(10);

    std::weak_ptr<int> weak_ptr(shared_ptr); // does NOT increase use_count
 
    // we cannot access the object directly because the object might not be valid instead we do
    if (std::shared_ptr<int> access = weak_ptr.lock()) // returns a shared pointer to the pointee or nullptr if the object is destroyed

        std::cout << "weak_ptr points to an existing element and that is: " << *access << std::endl;

    std::cout << "weak pointer " << ((weak_ptr.expired()) ? "is " : "is NOT " ) << "expired" << std::endl;

    return EXIT_SUCCESS;
}