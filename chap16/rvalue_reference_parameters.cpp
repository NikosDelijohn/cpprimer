#include <iostream>

template <typename U> 
void incr(U& arg)
{
    ++arg;
}

template <typename T>
void func(T&& val)
{
    // 1) if val is lvalue then T is T& !
    // 2) if val is literal then T is T !

    T t = val;
    // if 1) then t is bound to val
    // if 2) then t is copy-initialized from val

    incr(t);
    // if 1) then t AND val are incremented
    // if 2) then t is only incremented

    if (t == val)
    {
        std::cout << "You called me with an Lvalue ref\n";
    }
    
    else
    {
        std::cout << "You called me with an Rvalue ref\n";
    }

    std::cout << std::boolalpha << std::is_reference<T>::value << " "
        << std::is_reference<decltype(t)>::value << '\n';

}

int main()
{
    int lval = 1;
    func(lval);
    func(1);
}