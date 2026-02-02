#include <iostream>
#include <string>
#include <sstream>

template <typename T>
std::string debug_rep(const T &t)
{
    std::ostringstream ret;
    ret << "[const T&] " << t;
    return ret.str();    
}

template <typename T>
std::string debug_rep(T* ptr)
{
    std::ostringstream ret;

    if (ptr)
        ret << "[T*] -> " << debug_rep(*ptr);
    else
        ret << "[T*] null ptr";

    return ret.str();
}

template<>
std::string debug_rep(const char* cstr)
{
    std::ostringstream ret;
    ret << "[const char*] \"" << cstr << "\"";
    return ret.str();
}

template<>
std::string debug_rep(char* str)
{
    std::ostringstream ret; 
    ret << "[char*] \"" << str << "\"";
    return ret.str();
}

int main()
{
    int i = 42;
    int* ip = &i;

    std::string s = "hello";
    std::string* sp = &s;

    char buf[] = "world";
    char* cp = buf;

    const char* ccp = "literal";

    const char** cpp = &ccp;

    std::cout << debug_rep(i)   << '\n';   // const T&
    std::cout << debug_rep(ip)  << '\n';   // T*
    std::cout << debug_rep(s)   << '\n';   // const T&
    std::cout << debug_rep(sp)  << '\n';   // T*
    std::cout << debug_rep(cp)  << '\n';   // char* specialization
    std::cout << debug_rep(ccp) << '\n';   // const char* specialization
    std::cout << debug_rep("hi")<< '\n';   // const char* specialization
    std::cout << debug_rep(cpp) << '\n';   // T* → then const char*

    return EXIT_SUCCESS;
}