#include <iostream>
#include <string>

std::istream &to_out(std::istream &in)
{
    std::istream::iostate old_state = in.rdstate();
    
    std::string input;
    while(in>>input)
    {
        std::cout << input << std::endl;;
    }

    in.setstate(old_state);
    return in;
}

int main()
{
    decltype(to_out(std::cin)) strm = to_out(std::cin);

    return 0;
}