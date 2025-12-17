#include <iostream>

// Forward declarations of template
template <typename T>
class Box;

template <typename T>
class Wrapper;

template <typename T>
class AllSeeing;

// Class that wants to befriend multiple other classes
class Secret 
{
private:
    int value = 42;

    // One class, multiple friends. We have do explicitly
    // specify which instances of the Template class will
    // be befriended.

    friend class Box<int>;       // friend #1
    friend class Box<double>;    // friend #2
    friend class Wrapper<char>;  // friend #3

    // ALL instances of AllSeeing are friends with Secret!
    template <typename T> friend class AllSeeing;
};

template <typename T>
class Box 
{
public:
    void reveal(const Secret& s) 
    {
        std::cout << "Box<" << typeid(T).name() 
                  << "> sees secret: " << s.value << "\n";
    }
};

template <typename T>
class Wrapper 
{
public:
    void reveal(const Secret& s) 
    {
        std::cout << "Wrapper<" << typeid(T).name() 
                  << "> sees secret: " << s.value << "\n";
    }
};

template <typename T>
class AllSeeing
{
public:
    void reveal(const Secret& s)
    {
        std::cout << "AllSeeing<" << typeid(T).name()
                  << "> sees secret: " << s.value << "\n";
    }
};

int main() 
{
    Secret s;

    Box<int> bInt;
    Box<double> bDouble;
    Wrapper<char> wChar;

    AllSeeing<float> panoptes;

    bInt.reveal(s);     // OK
    bDouble.reveal(s);  // OK
    wChar.reveal(s);    // OK

    Box<float> bFloat;
    //bFloat.reveal(s); // ERROR: not a friend
    /*
one_to_many_friendship.cpp: In instantiation of ‘void Box<T>::reveal(const Secret&) [with T = float]’:
one_to_many_friendship.cpp:79:20:   required from here
one_to_many_friendship.cpp:38:45: error: ‘int Secret::value’ is private within this context
   38 |                   << "> sees secret: " << s.value << "\n";
      |                                           ~~^~~~~
    */

    panoptes.reveal(s);
}