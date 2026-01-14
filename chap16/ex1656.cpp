#include <iostream>
#include <sstream>
#include <string>

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

    if (ptr)
        ss << debug_rep(*ptr);
    else
        ss << "nullptr";

    return ss.str();
}

std::string debug_rep(const char* cstr)
{
    std::cout << "->debug(const char* cstr)\n";
    return debug_rep(std::string(cstr));    
}

template<typename T>
std::ostream& print(std::ostream& out, const T& obj)
{
    return out << obj; // reminder operator<<() returns the stream 
} 

template<typename T, typename... Args>
std::ostream& print(std::ostream& out, const T& curr, const Args&... rest)
{
    out << curr << ", ";
    return print(out, rest...);
    /*
    or 
    print(out, rest...);
    return out;
    */
}

template <typename... Args>
std::ostream& error_message(std::ostream& out, const Args&... args)
{
    return print(out, debug_rep(args)...);
}

int main()
{
    int i = 1; // handled by recursive print 
    double d = 3.14; // same
    float f = 5.20; // same
    const char* cstr = "c-style str"; // this will be handled by the base-case print 

    error_message(std::cout, i, d, f, cstr) << std::endl;

    return EXIT_SUCCESS;
}