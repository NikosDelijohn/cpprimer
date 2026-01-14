#include <iostream>
#include <sstream>
#include <string>

template<typename T>
std::string debug_rep(const T&);

template<typename T>
std::string debug_rep(T*);


template <typename T>
std::string debug_rep(const T& obj) 
{
    std::cout << "->debug(const T& obj)\n";

    std::ostringstream ss;
    ss << obj;
    return ss.str();
}

template <typename T>
std::string debug_rep(T* ptr)
{
    std::cout << "->debug(T* ptr)\n";

    std::ostringstream ss;
    ss << "[pointer]: ";

    if (ptr)
        ss << debug_rep(*ptr);
    else
        ss << "nullptr";

    return ss.str();
}

int main()
{
    std::string *s_ptr = new std::string("Hahaha!");
    double *d_ptr = new double(42.0);

    debug_rep(d_ptr);
    debug_rep(s_ptr);

    debug_rep("C-style str");

    delete d_ptr, s_ptr;

    return EXIT_SUCCESS;
    
}