#include <iostream>


/*

An expression like expr->id depends on the type of expr. If expr is a built-in pointer then ot translates to (*expr).id

But, if expr is an object of class-type AND has an overloaded -> operator then:

if expr.operator->() doesn't return a raw pointer it MUST RETURN an object of class-type that defines its own operator->() overload
then, expr.operator->() becomes expr.operator->().operator->() 
    if expr.operator->().operator->() doesn't return a raw pointer IT MUST RETURN an object of class-type that defins its own operator->() overload
    then, expr.operator->().operator->() becomes expr.operator->().operator->().operator->()
        ...
        and so on, until it's finally applying the -> operator to a raw pointer.

When the -> succeeds and fetches the raw pointer, this pointer is used to fetch the requested id member

So called 'Drill-Down' behavior!

*/

struct point
{
    int x; 
    int y;
};

struct st_ptr
{
    point* proxy;

    inline point& operator*() const noexcept
    {
        return *proxy;   // return reference to the pointee
    }
    
    // Halt! It DOES return a pointer! fetch the .mem now!
    inline point* operator->() const noexcept             // <- ... we now invoke the returned value's operator->() again
    {                                                     //
        return & this->operator*();                       //
    }                                                     //
                                                          //
};                                                        //
                                                          //
struct st_ptr_2                                           //
{                                                         //
    st_ptr* proxy;                                        //
                                                          //
    inline st_ptr& operator*() const noexcept             //   
    {                                                     //
        return *proxy;                                    //
    }                                                     // 
    // But still doesn't return a ptr! thus! ---------------
    inline st_ptr& operator->() const noexcept                 // <- ...we now invoke the returned value's operator->() again
    {                                                          // 
        return this->operator*();                              // 
    }                                                          // 
                                                               //
};                                                             //
                                                               // 
struct st_ptr_3                                                //
{                                                              //
    st_ptr_2* proxy;                                           //
                                                               //
    inline st_ptr_2& operator*() const noexcept                //
    {                                                          //
        return *proxy;                                         //
    }                                                          //
                                                               //
    // doesn't return a ptr! thus! -------------------------------
    inline st_ptr_2& operator->() const noexcept
    {
        return this->operator*();
    }
    
};

int main()
{

    point a {1,2};
    st_ptr ptr {&a};
    st_ptr_2 ptr2 {&ptr};
    st_ptr_3 ptr3 {&ptr2};

    std::cout << (*ptr).x << ptr->x << ptr2->x << ptr3->x << std::endl;
    // what goes on under the curtain is:
    //                  object       object       ptr! stop!
    std::cout << (*ptr3.operator->().operator->().operator->()).x ;
    
    return 0;
}