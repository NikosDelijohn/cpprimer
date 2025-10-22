#ifndef _HELP_
#define _HELP_

#include <iostream>
#include <typeinfo>
#include <cxxabi.h>
#include <memory>
#include <bitset>
#include <type_traits>

template <typename T>
std::string type_name(const T& obj)
{
    int status;
    char* demangled = abi::__cxa_demangle(typeid(obj).name(), nullptr, nullptr, &status);
    std::string result = (status == 0) ? demangled : typeid(obj).name();
    std::free(demangled);
    return result;
}

template <typename T>
void print_bits(const T& value)
{
    static_assert(std::is_integral<T>::value, "Not an integral type!");

    constexpr size_t bits = sizeof(T) * 8;
    std::bitset<bits> bs(static_cast<unsigned long long>(value));

    std::cout << bs << " (" << value << ")" << std::endl;
}

#endif