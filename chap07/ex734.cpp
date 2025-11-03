#include <iostream>

class Screen 
{
public:
    
    void dummy_fcn(pos height)
    {
        // 
    }
    typedef std::string::size_type pos;
};

/*
Function signatures are compiled in-order. Only the bodies are compiled after the whole
class has been defined. Hence, here we are in error because no type declaration for pos
is done before reaching the member function.

*/