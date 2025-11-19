#include <iostream>
#include <initializer_list>
#include <utility>

class T {
public:
    // Constructors
    T() {
        std::cout << "T()  [default/value initialization]\n";
    }

    T(const T&) {
        std::cout << "T(const T&)  [copy constructor]\n";
    }

    T(T&&) {
        std::cout << "T(T&&)  [move constructor]\n";
    }

    T(std::initializer_list<int>) {
        std::cout << "T(std::initializer_list<int>)  [initializer_list constructor]\n";
    }
};

T makeT() {
    std::cout << "Entering makeT()\n";
    T temp{};  // value initialization → T()
    std::cout << "Returning temp\n";
    return temp;  // RVO or move
}

void passByValue(T x) {  // copy constructor
    std::cout << "Inside passByValue()\n";
}

int main() {

    std::cout << "\n--- 1. Default Initialization ---\n";
    T a;   // T()

    std::cout << "\n--- 2. Value Initialization ---\n";
    T b{};       // T()
    T c = T{};   // T()
    T* p = new T(); // T()
    delete p;

    std::cout << "\n--- 3. Direct Initialization ---\n";
    T d(a); // copy constructor

    std::cout << "\n--- 4. Copy Initialization ---\n";
    T e = a; // copy constructor

    std::cout << "\n--- 5. Direct List Initialization ---\n";
    T f{1, 2, 3}; // initializer_list ctor

    std::cout << "\n--- 6. Copy List Initialization ---\n";
    T g = {4, 5, 6}; // initializer_list ctor

    std::cout << "\n--- 7. List Initialization with Object ---\n";
    T h{a};      // copy constructor
    T i = {a};   // copy constructor

    std::cout << "\n--- 8. Move Initialization ---\n";
    T j = std::move(a); // move constructor

    std::cout << "\n--- 9. Pass-by-value ---\n";
    passByValue(a); // copy constructor

    std::cout << "\n--- 10. Return-value initialization ---\n";
    T k = makeT(); // RVO, or move/copy depending on compiler

    std::cout << "\n--- 11. Throw/catch by value ---\n";
    try {
        throw a;  // copy constructor
    } catch (T x) {
        std::cout << "Caught exception by value\n";
    }

    return 0;
}