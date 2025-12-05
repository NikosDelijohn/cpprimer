#include <iostream>

small_int operator+(const small_int &, const small_int &);

class small_int
{
    friend small_int operator+(const small_int &, const small_int &);
public:
    small_int(int i = 0): val(i)
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad small_int value");
    }

    operator int() const 
    {
        return val;
    }

private:
    size_t val;
};

int main()
{

    small_int si;
    double d = si + 3.14; // ambiguous call

    /*
        small_int -> int -> double and
        double -> int -> small_int is feasible
    */

}