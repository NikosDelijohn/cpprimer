#include <string>
#include <iostream>
#include <cstring>


// [A] Nontype parameters can be constant expressions of integral types
template<unsigned N, unsigned M>
const char* compare (const char (&a)[N], const char (&b)[M])
{
    return (std::strcmp(a,b) <= 0) ? a : b;
}

// [B] Nontype parameters can be pointers with pointees of a static lifetime
template<const int* ptr>
void print_ptr()
{
    std::cout << *ptr << "\n";
}

static int x = 42;
constexpr int y = 43;

// [C] Nontype parameters can be pointers to functions 
void post();

template<void (*decorator)(void)>
void decorate(void (*func)(void))
{
    decorator();
    func();
    post();
}

void pre()
{
    std::cout << "pre() invoked\n";
}
void post()
{
    std::cout << "post() invoked\n";

}
void func()
{
    std::cout << "func() invoked\n";
}

// [D] Nontype parameters can be lvalue references to constexpr objects
constexpr int j = 42;

template<const int& ref>
void print_ref() 
{
    std::cout << ref << std::endl;
}

int main()
{
    /*
    Nontype parameters represent a value rather than a type. They are specified using a type name 
    */
    
    // Here, the compiler will use the size of the literals to instantiate
    // the version of the template that substitutes the N and M nontypes accordingly
    auto res = compare("hi","world");
    std::cout << res <<std::endl;

    // [B]
    print_ptr<&x>();
    print_ptr<&y>();

    // [C]
    decorate<pre>(func);

    // [D] 
    print_ref<j>();


    return EXIT_SUCCESS;
}