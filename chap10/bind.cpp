#include <iostream>
#include <functional>

void foo(int a, int b)
{
    std::cout << "got: " << a << " " << b << std::endl;
}

void print_to(std::ostream &os, const std::string &msg)
{
    os << msg << std::endl;
}

int main()
{
    foo(1,2);

    auto reorder_args = std::bind(foo, std::placeholders::_2, std::placeholders::_1);
    /*
    1. Generate a new callable named reorder_args
    2. It is based on foo and
    3. its first argument (_1) will be used as the second argument to foo
    4. its second argument (_2) will be used as the first argument to foo
    */

    reorder_args(1,2); // reordering args

    auto partial_invocation = std::bind(foo, std::placeholders::_2, 5);
    /*
    1. Generate a new callable named partial_invocation
    2. It is based on foo and
    3. Its first argument is ignored
    4. Its second argument is used as the first argument to foo
    5. Foo is always called with the second argument being 5  
    */

    partial_invocation(-1,5); // -1 is ignored

    auto correct_partial_invocation = std::bind(foo, std::placeholders::_1, 5);
    /*
    1. Generate a callable that binds foo's second argument to 5
    2. Only the first argument remains free
    */

    correct_partial_invocation(1);

    // --- std::ref / std::cref example ---

    /*
    1. Some types like std::ostream are non-copyable.
    2. std::bind copies arguments by default.
    3. To pass such objects by reference, use std::ref (or std::cref for const ref).
    */

    auto bound_printer = std::bind(print_to, std::ref(std::cout), std::placeholders::_1);
    bound_printer("Hello from std::ref!");

    return EXIT_SUCCESS;
}
