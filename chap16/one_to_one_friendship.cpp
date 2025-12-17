#include <iostream>

/*
For dependent templates (like Box<T>), the compiler must know it’s a template first → forward declaration is required.
*/
template <typename T> class Box; // forward declaration

// Class that wants friendship per type
template <typename T>
class Secret 
{
    // Make **Box<T>** a friend — only the matching type!!
    friend class Box<T>;

private:
    T value;

public:
    Secret(T v) : value(v) {}

};

// Class template that can access Secret<T> of same type
template <typename T>
class Box 
{
public:
    void reveal(const Secret<T>& s) 
    {
        // Allowed because Box<T> is friend of Secret<T>
        std::cout << "Secret value is: " << s.value << "\n";
    }
};

int main() 
{
    Secret<int> sInt(42);
    Box<int> bInt;
    bInt.reveal(sInt);  // OK

    Secret<double> sDouble(3.14);
    Box<double> bDouble;
    bDouble.reveal(sDouble);  // OK

    // bInt.reveal(sDouble); // ERROR: Box<int> is not friend of Secret<double>
}