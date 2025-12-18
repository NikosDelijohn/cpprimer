// 1) Same-type operator== (Box<T> == Box<T>) with 1–1 friendship
// 2) Cross-type operator== (Box<T> == Box<U>) with many–many friendship

#include <iostream>

//------------------------------------------------------------
// Forward declarations
//------------------------------------------------------------
template <typename T>
class Box;

// (A) SAME-TYPE operator template
template <typename T>
bool operator==(const Box<T>&, const Box<T>&);

// (B) CROSS-TYPE operator template
template <typename T, typename U>
bool operator==(const Box<T>&, const Box<U>&);

//------------------------------------------------------------
// Class template
//------------------------------------------------------------
template <typename T>
class Box
{
public:
    explicit Box(T v) : value(v) {}

private:
    T value;

    // --------------------------------------------------------
    // (A) Befriend the SAME-TYPE operator template
    //
    // operator==<> means:
    //   “Use the already-declared function template operator==”
    // For Box<T>, this befriends operator==<T>
    // (1–1 relationship)
    // can also be operator==<T>
    // --------------------------------------------------------
    friend bool operator==<>(const Box&, const Box&);

    // --------------------------------------------------------
    // (B) Befriend the CROSS-TYPE operator template
    //
    // This is a *templated friend declaration*.
    // It befriends ALL instantiations of:
    //   operator==<X, Y>
    // (many–many relationship)
    // --------------------------------------------------------
    template <typename X, typename Y>
    friend bool operator==(const Box<X>&, const Box<Y>&);
};

//------------------------------------------------------------
// (A) SAME-TYPE operator definition
//------------------------------------------------------------
template <typename T>
bool operator==(const Box<T>& lhs, const Box<T>& rhs)
{
    std::cout << "[same-type operator==]\n";
    return lhs.value == rhs.value;
}

//------------------------------------------------------------
// (B) CROSS-TYPE operator definition
//------------------------------------------------------------
template <typename T, typename U>
bool operator==(const Box<T>& lhs, const Box<U>& rhs)
{
    std::cout << "[cross-type operator==]\n";
    return lhs.value == rhs.value; // requires T == U to be valid
}

//------------------------------------------------------------
// Usage
//------------------------------------------------------------
int main()
{
    Box<int>    a(10), b(10), c(20);
    Box<double> d(10.0);
    Box<char>   e('A');

    // Same-type comparisons
    std::cout << (a == b) << '\n'; // same-type operator
    std::cout << (a == c) << '\n'; // same-type operator

    // Cross-type comparisons
    std::cout << (a == d) << '\n'; // cross-type operator
    std::cout << (a == e) << '\n'; // cross-type operator

    return 0;
}
