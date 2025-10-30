#include <iostream>
#include <string>
using std::string;

struct Person
{
    string name;
    string surname;
    string address;

    inline
    string get_name() const { return name;}
    inline 
    string get_surname() const { return surname;}
    inline // redundant but still, better readability.
    string get_address() const {return address;}
};