#include <iostream>

int main()
{

    const int i = 42;
    auto j = i; const auto &k = i; auto *p = &i;
    const auto j2 = i, &k2 = i;

    // i is const int
    // j is int 
    // k is const int & , const is redundant here.
    // p is const int *
    // j2 is const int 
    // k2 is const int &
    
    return 0;
}