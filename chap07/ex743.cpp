#include <iostream>

class NoDefault
{
public: 
    NoDefault(int some_int):
        value(some_int){}
    
private:
    int value;
};

class C
{
public:
    C(): 
        value(0u)
    {}

private:
    NoDefault value;
    int another_val;
};

int main()
{
    C dummy;


    return EXIT_SUCCESS;
}