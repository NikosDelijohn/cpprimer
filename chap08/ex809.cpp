#include <iostream>
#include <string>
#include <sstream>

std::istream &to_out(std::istream &in)
{
    std::istream::iostate old_state = in.rdstate();
    
    std::string input;
    while(in>>input)
    {
        std::cout << input << std::endl;
    }

    in.setstate(old_state);
    return in;
}

int main()
{   
    std::istringstream ss("This is an input stringstream");
    to_out(ss);
}   