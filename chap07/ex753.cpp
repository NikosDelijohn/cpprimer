#include <iostream>

class debug
{
public:

    constexpr debug(bool val = true): hw(val), io(val), other(val) {};
    constexpr debug(bool hwval, bool ioval, bool otherval ):
    hw(hwval), io(ioval), other(otherval){}

    constexpr bool any() { return hw || io || other; }
    void set_io(bool val) { io = val;}
    void set_hw(bool val) { hw = val;}
    void set_other(bool val) {other = val;}

private:
    bool hw;
    bool io;
    bool other;
};

int main()
{
    debug dbg;
    dbg.set_hw(true);

    return EXIT_SUCCESS;
}