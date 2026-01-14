#include <iostream>
#include <utility>

template <typename T1, typename T2>
void incr(T1 arg1, T2& arg2)
{
    // (4)
    // T1 is a nonreference type
    // T2 is an lvalue reference type

    ++arg1; // increment will not be reflected to caller
    ++arg2; // increment will be reflected to caller
}

template <typename Func, typename T1, typename T2>
void flip(Func f, T1&& t1, T2&& t2)
{   
    // (2)
    // T1 and T2 are passed lvalues, hence the T is now T&
    // T&(&&) -> T& hence t1,t2 are lvalue refs.

    std::cout << "\tt1=" << t1 << " t2=" << t2 << std::endl;
    f(t1,t2); // (3) t1, t2 are lvalue references
    std::cout << "\tt1=" << t1 << " t2=" << t2 << std::endl;

    ++t1, ++t2; // (5) these changes will be reflected to caller
}

// --------------------- // 

template <typename T1, typename T2>
void incr2(T1&& arg1, T2&& arg2)
{

    ++arg1; // increment will not be reflected to caller
    ++arg2; // increment will be reflected to caller
}

template <typename Func, typename T1, typename T2>
void flip2(Func f, T1&& t1, T2&& t2)
{
    std::cout << "\tt1=" << t1 << " t2=" << t2 << std::endl;
    f(t1,t2);
    std::cout << "\tt1=" << t1 << " t2=" << t2 << std::endl;
}

template <typename T1, typename T2>
void flip3(T1&& t1, T2&& t2)
{
    std::cout << "\tt1=" << t1 << " t2=" << t2 << std::endl;
    incr2(std::forward<T1>(t1), std::forward<T2>(t2));
    std::cout << "\tt1=" << t1 << " t2=" << t2 << std::endl;
}

int main()
{
    int arg1 = 5, arg2 = 5;

    std::cout << "arg1=" << arg1 << " arg2=" << arg2 << std::endl;
    flip(incr<int, int>, arg1, arg2); // (1) arg1, arg2 are lvalues
    std::cout << "arg1=" << arg1 << " arg2=" << arg2 << std::endl;

    // ----------------- //

    std::cout << "\n\n";

    int arg3 = 5, arg4 = 5;

    //flip2(incr2<int, int>, arg3, arg4); // this will not compile!
    /*
    arg3, arg4 are lvalues, they can bind to flip2's without error due to forwarding reference parameters (rvalue refs).
    However, incr2 cannot be invoked. because t1 and t2 are lvalues. They cannot be bound to the rvalue ref params of incr2.

    This is why, we need std::forward. To preserve the rvalue-ness of these types.
    */

    
    std::cout << "arg3=" << arg3 << " arg4=" << arg4 << std::endl;
    flip3(arg3, arg4); // invoked with lvalues - changes will be reflected - std::forward will return an lvalue ref 
    std::cout << "arg3=" << arg3 << " arg4=" << arg4 << std::endl;

    std::cout << "\n\n";
    flip3(40, 50); // changes are reflected only withing flip3 as the temporaries will live there - std::Forward will return an rvalue ref



    return EXIT_SUCCESS;
}