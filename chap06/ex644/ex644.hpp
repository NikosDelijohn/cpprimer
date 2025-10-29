#ifndef _EX644_
#define _EX644_

#include <string>

constexpr bool is_shorter(const std::string &s1, const std::string &s2)
{
    return s1.size() < s2.size();
}

#endif 