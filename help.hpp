#ifndef _HELP_
#define _HELP_

#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <memory>

template <typename T>
std::string type_name(const T& obj)
{
    int status;
    char* demangled = abi::__cxa_demangle(typeid(obj).name(), nullptr, nullptr, &status);
    std::string result = (status == 0) ? demangled : typeid(obj).name();
    std::free(demangled);
    return result;
}

#endif