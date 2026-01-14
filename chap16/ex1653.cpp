#include <iostream>

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

int main()
{
    int i = 1; // handled by recursive print 
    double d = 3.14; // same
    float f = 5.20; // same
    const char* cstr = "c-style str"; // this will be handled by the base-case print 
    

    print(std::cout, i, d, f, cstr) << std::endl;

}