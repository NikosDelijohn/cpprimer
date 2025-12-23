#include <string>

template <typename T> class Stack{};

void f1 (Stack <char>); // (a)

class Exercise 
{
    Stack<double> &rsd; // (b)
    Stack<int> si; // (c)
};

int main()
{
    Stack<char> *sc; // (d)
    f1(*sc); // (e)
    int iObj = sizeof(Stack<std::string>); // (f)
    return 0;
}


/*
(a): This is a forward declaration of the function f1. No complete type is required and thus
     the compiler will not instantiate Stack<char>. No instantiation happens.

(b) & (c): These are member declarations. Member declarations do not require a complete type.
           Therefore, the compiler will not instantiate Stack<double> or Stack<int>.
           No instantiation happens.

(d): This line declares a raw pointer to Stack<char>. A pointer does not require a complete
     type. No instantiation happens.

(e): The argument is passed by value to f1. This requires generating code to copy/move the
     argument into the parameter and to destroy it at the end of the call. Therefore, the
     type must be complete at this point. As a result, the compiler instantiates Stack<char>.

(f): sizeof requires a complete type in order to determine its size. Thus the compiler
     instantiates Stack<string>.

NOTE: None of these cause instantiation of all members. Only the parts of each class
      that are required (layout, copy/move ctor, destructor, etc.) are instantiated.
      
*/