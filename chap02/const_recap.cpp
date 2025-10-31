#include <iostream>

int runtime_init() { return 1; }

int main()
{
    // High-level const: The value cannot change.
    // Low-level const (compound) types: The point-to value or bound value is const and cannot change.

    const int a_value = 100; // - or -
    const int b_value = runtime_init(); // - or -
    const int c_value = a_value + b_value; 

    // Fine as long as we do not modify those high-level consts as:
    // a_value = b_value + 1; // error: assignment of read-only variable ‘a_value’ 

    /*
                __                                  
               / _|                                 
      _ __ ___| |_ ___ _ __ ___ _ __   ___ ___  ___ 
     | '__/ _ \  _/ _ \ '__/ _ \ '_ \ / __/ _ \/ __|
     | | |  __/ ||  __/ | |  __/ | | | (_|  __/\__ \
     |_|  \___|_| \___|_|  \___|_| |_|\___\___||___/

    */
    
    // Then we get to have references too.
    // By definition references are high-level consts. They are aliases for types
    // and their value cannot be re-assigned. Using the assignment operator on 
    // references simply modifies the bound type of that reference accordingly.
    
    // But also, const references are always low-level. 
    const int &ref_a = a_value; // - or you can even -

    int just_an_int = 123;
    const int &ref_b = just_an_int; // Bind to a non-const type. This is ok.

    // What this means, is that we have a constant reference to a non-const type.
    // The type can modify itself but the reference cannot, its read-only! So:
    just_an_int += 1; // is fine, its 124
    // ref_b += 1 // but this not! ref is constant reference to int!

    std::cout << "just_an_int = " << just_an_int << std::endl 
              << "  and ref_b = " << ref_b << std::endl;

    // Weirdly, you can also do this:
    double its_pi = 3.14;
    const int &int_ref = its_pi; // constant reference to int initialized with a double

    // But now, when we modify the bound-to object, the reference is not updated!
    its_pi += 1.0;
    std::cout << "its_pi  = " << its_pi << std::endl 
              << "int_ref = " << int_ref << std::endl;

    // Internally C++ creates a temporary object, converts to the requested const ref type
    // and assigns this temporary object to the reference. Which makes it impossible for 
    // the reference to be updated at run-time when the non-const bound-to object changes!

    /*
                 _       _                
                (_)     | |               
    _ __   ___  _ _ __  | |_ ___ _ __ ___ 
    | '_ \ / _ \| | '_ \| __/ _ \ '__/ __|
    | |_) | (_) | | | | | ||  __/ |  \__ \
    | .__/ \___/|_|_| |_|\__\___|_|  |___/
    | |                                   
    |_|

    */

    // Now to pointers
    int typical_int = 123;
    const int const_typical_int = 123;
    
    // 'const type *pointer' variation
    // means pointer to constant type which can be:
    const int *ptr = &const_typical_int; // a constant type. 
    const int *ptr2 = &typical_int; // but also a non-constant type! this is fine too

    // Similarly to the references part, this means that the pointer in both cases 
    // has read-only access to the pointee. The object cannot be modified via the 
    // pointer using the dereference operator *.

    // These pointers are low-level consts. They 'think' they point to const objects.
    // But the pointers themselves are not const! They can be freely re-assigned like:
    ptr2 = &const_typical_int; // This is fine! -or-
    const int *ptr3; // be left uninitialized and just declared. 
    //*ptr2 += 1 // but as we said, they are read-only! Cannot modify the pointee.

    // These pointers on the other hand, are constant:
    const int *const cptr = &const_typical_int; // left const is low level, right const is high-level
    int *const cptr2 = &typical_int; // const is just high-level;
    //int *const cptr3 = &const_typical_int; // this is not allowed! cause pointer could modify (via *) the value of a const object. top level constness says nothing about the constness of the underlying object.

    const int *const cptr3 = &typical_int; // remember, this is also fine. the pointee can be a non-const type.
    typical_int++;

    // Constant pointers to constant objects must always be initialized when declared.
    //const int *const cptr4; // not allowed!

    /*
                  _        
                 | |       
       __ _ _   _| |_ ___  
      / _` | | | | __/ _ \ 
     | (_| | |_| | || (_) |
      \__,_|\__,_|\__\___/ 


    */
    int i = 42;
    const int ci = i, &cr = ci;

    auto b = ci; // ok! cr is const (high-level) hence dropped. b is int
    auto c = cr; // ok! cr = ci (high-level) hence dropped. c is int
    auto d = &i; // ok! d is int *
    auto e = &ci; // e is const int pointer; (low-level)
    // Here, observe and note that the top-level constness of the initializer 'ci' is NOT ignored.

    // For high-level const we must do it explicitly
    const auto f = &ci; // f is top-level const and also low-level const.

    // In auto references, top-level constness (of initializer) IS NOT IGNORED during type deduction!!!
    const int ci2 = 42;
    auto &g = ci2; // g is not int &, but it is const int &! Which makes it a low-level const.

    /*
    Overall, top-level const is ignored during:
      - Copy initialization
      - Assignment
      - Type deduction when the constness applies ONLY to the source object (ex. const auto var = )
    
    */

    /*
      __  __                _                 ______                    
     |  \/  |              | |               |  ____|                   
     | \  / | ___ _ __ ___ | |__   ___ _ __  | |__ _   _ _ __   ___ ___ 
     | |\/| |/ _ \ '_ ` _ \| '_ \ / _ \ '__| |  __| | | | '_ \ / __/ __|
     | |  | |  __/ | | | | | |_) |  __/ |    | |  | |_| | | | | (__\__ \
     |_|  |_|\___|_| |_| |_|_.__/ \___|_|    |_|   \__,_|_| |_|\___|___/
                                                                        
                                                                        
    */

    /*
    When it comes to classes and member functions it is possible to append const
    after the functions parameter list
    */

    class const_and_noncost
    {
    public:

        int value_a = 10u;
        int value_b = 100u;

        void some_non_const_func() // ClassName* const this;
        {
            std::cout << "Non Const Func Called!" << std::endl;
        }

        void a_const_func() const // const ClassName* const this;
        {
            std::cout << "Const Func Called!" << std::endl;
        }
        
        // Overloaded based on const now! Misleading func name however...
        void some_non_const_func() const // const ClassName* const this;
        {
            std::cout << "Overloaded Const Func Called!" << std::endl;
        }

        // A const function cannot simply return *this.
        // this is a const ClassName* const pointer
        // which means that it points to a const object! Hence the return
        // type must be const (to return a copy) or const & (to return a read-only reference)
        const const_and_noncost returns_copy_of_this() const
        {
          return *this;
        }

        const const_and_noncost& returns_ref_of_this() const
        {
          return *this;
        }
               
    };

    /*
    By default its member function has access to the pointer `this`.
    it is a constant pointer which points to the class's instance.
    In a non-const member function, `this` is of type `ClassName* const` 
    (the pointer itself is const), so you can modify the object it points to.

    */

    const_and_noncost non_const_object; // default initialized with in-class initializers
    const const_and_noncost const_object; // similarly
    
    // We can freely invoke both functions from the non_const_object.
    non_const_object.some_non_const_func(); // ok!
    non_const_object.a_const_func(); // ok!
    // for both this is initialized to point to non_const_object.                             fine: low-level nonconst <- nonconst is allowed!
    
    // But we CANNOT invoke the some_non_const_func() from the const object!
    const_object.a_const_func(); // ok! `this` is const object *const ptr.                    fine: low-level const <- const is allowed!
    //const_object.some_non_const_func(); // wrong!
    // There are no guarantees that the some_non_const_func() wont modify the const object! not ok: low-level nonconst <- const is NOT allowed! 

    // However, we can overload the non_const function to be const! And now we can freely
    const_object.some_non_const_func(); // compiler detects and resolves the overloaded function based on constness
    
    std::cout << const_object.returns_ref_of_this().value_a << std::endl; // expect 10
}