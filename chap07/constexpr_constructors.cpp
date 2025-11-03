#include <iostream>
#include <cassert>


class Debug {
public:
    // constexpr constructor allows compile-time creation
    constexpr Debug(bool hwval = true, bool ioval = true, bool otherval = true)
        : hw(hwval), io(ioval), other(otherval) {}

    // constexpr member function for compile-time evaluation
    constexpr bool any() const { return hw || io || other; }

    // runtime-modifiable setters (cannot be constexpr in practice)
    void set_hw(bool val) { hw = val; }
    void set_io(bool val) { io = val; }
    void set_other(bool val) { other = val; }

    void print() const {
        std::cout << std::boolalpha
                  << "HW: " << hw
                  << ", IO: " << io
                  << ", Other: " << other
                  << "\n";
    }

private:
    bool hw;
    bool io;
    bool other;
};

int main() {
    // ------------------------------
    // 1. Compile-time constant object
    // ------------------------------
    constexpr Debug dbg_const(true, false, true);
    static_assert(dbg_const.any(), "dbg_const should have at least one true");
    // dbg_const.set_hw(false); // Error: cannot modify a constexpr object
    std::cout << "dbg_const.any() at compile-time: " << dbg_const.any() << "\n";

    // ------------------------------
    // 2. Runtime object (mutable)
    // ------------------------------
    Debug dbg_runtime(false, false, false); // ordinary object
    dbg_runtime.print();                     // initial state

    // modify runtime object
    dbg_runtime.set_io(true);
    dbg_runtime.set_other(true);
    dbg_runtime.print();                     // modified state

    return 0;
}