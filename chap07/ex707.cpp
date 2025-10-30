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

std::ostream &print(std::ostream &out, const Person &person)
{
    out << person.name << " " << person.surname << " @ " << person.address << std::endl;
    return out;
}

std::istream &read(std::istream &in, Person &person)
{
    in >> person.name >> person.surname >> person.address;
    return in;
}

