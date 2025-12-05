#include <iostream>

class small_int
{
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

class small_int_explicit
{
public:
    small_int_explicit(int i = 0): val(i)
    {
        if (i < 0 || i > 255)
            throw std::out_of_range("Bad small_int value");
    }

    explicit operator int() const 
    {
        return val;
    }

    explicit operator bool() const 
    {
        return val != 0;
    }

private:
    size_t val;
};
int main()
{
    small_int si;

    si = 4; // implicitly converts 4 to small_int (implicit ctor)
            // then calls synthesized copy-ctor;
    
    si + 3; // implicitly converts si to int then performs addition

    si + 3.14; // smallint convertor converts si to int, int is converted to double using built-in conversion
    // Although the compiler performs only one user-defined implicit cast
    // here we actually comply with that rule since we only provide our int() cast.
    // the conversion of an int to double is done through the built-in rule, not ours!

    // However, conversion operators can yield surprising results due to their implicit
    // usage from the compiler during expression evaluation. We have to consider every potential
    // implicit use case of our conversion operator which can prove to be an arduous task.

    // For this reason, we define such conversion operators as explicit!

    small_int_explicit sie;
    
    sie = 4; // this is ok the ctor is implicit. int -> smallint ok!
    
    //sie + 3; // this is not Ok! sie must be converted explicitly to an int now
    static_cast<int>(sie) + 3; // ok!

    static_cast<int>(sie) + 3.14; // ok!

    // However! The constructor will still use an explicit convertor implicitly IF:
    /*
    1) The object is in an expression used as the condition of an IF, WHILE or DO statement
    2) The object is in the for statement header condition expression
    3) THe object is an operand to the logic NOT, OR or AND operators.
    4) It is in the condition expression in the conditional ?: operator
    */

    if(sie) // 1)
    {
        std::cout << "Implicit conversion done on explicit conversion operator\n";
        std::cout << static_cast<int>(sie) << " is non zero!\n";
    }

    small_int_explicit zero;
    if(zero)
    {
        std::cout << "This will not be printed\n";
    }

    // 2)
    for (size_t i = 1; sie; ++i)
    {
        std::cout << i << std::endl;
        // forcibly exiting the loop by breaking the condition
        sie = 0; // now implicit bool call will evaluate the FOR condition to false!
    }

    // 3)
    std::cout << std::boolalpha << "sie = " << static_cast<int>(sie) << " AND True is " << (sie && true) << std::endl;

    // 4)
    std::cout << ((sie) ? "Won't be printed" : "Another implicit conversion occured." ) << std::endl;

}