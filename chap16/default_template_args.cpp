#include <iostream>
#include <typeinfo>

/* ---------------- Default type ---------------- */

struct Default
{
    Default() {
        std::cout << "Default constructed\n";
    }
};

/* ---------------- Another type ---------------- */

struct Custom
{
    Custom() {
        std::cout << "Custom constructed\n";
    }
};

/* ---------------- Template with default type ---------------- */

template <typename Deleter = Default>
struct Holder
{
    Holder()
        : deleter(Deleter())
        /*
            Default-constructs an object of the template parameter type `Deleter`.
            If no deleter type was explicitly provided, `Deleter` is the default
            template argument; otherwise it is the user-supplied type.

            Deleter **Must** be default constructible!
        */
    {}

    Deleter deleter;
};

/* ---------------- Demonstration ---------------- */

int main()
{
    std::cout << "Case 1: no template argument\n";
    Holder<> h1;        // Deleter = Default
                        // Deleter{} -> Default{}

    std::cout << "\nCase 2: explicit template argument\n";
    Holder<Custom> h2;  // Deleter = Custom
                        // Deleter{} -> Custom{}
}