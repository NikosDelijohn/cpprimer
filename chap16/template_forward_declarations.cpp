#include <iostream>

//------------------------------------------------------------
// 1) Class template forward declaration
//    Template parameter can be anonymous because it is UNUSED
//------------------------------------------------------------
template <typename>
class ForwardOnly;   // OK: parameter count/type matters, name does not

//------------------------------------------------------------
// 2) Equivalent forward declaration with a named parameter
//------------------------------------------------------------
template <typename T>
class ForwardOnlyNamed;  // Also OK, but T is unused here

//------------------------------------------------------------
// 3) Function template forward declaration
//    Template parameter MUST be named because it is USED
//------------------------------------------------------------
template <typename T>
void process(const ForwardOnly<T>&);   // T is referenced → must be named

//------------------------------------------------------------
// 4) Definition of the class template
//    Now the parameter MUST be named because it is USED
//------------------------------------------------------------
template <typename T>
class ForwardOnly
{
public:
    explicit ForwardOnly(T v) : value(v) {}
    T get() const { return value; }

private:
    T value;
};

//------------------------------------------------------------
// 5) Definition of the function template
//------------------------------------------------------------
template <typename T>
void process(const ForwardOnly<T>& obj)
{
    std::cout << obj.get() << '\n';
}

//------------------------------------------------------------
// 6) Usage
//------------------------------------------------------------
int main()
{
    ForwardOnly<int> x(42);
    process(x);

    return 0;
}