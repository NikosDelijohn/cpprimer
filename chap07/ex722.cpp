#include "ex722.hpp"

using std::string;

Person::Person() = default;

Person::Person(const string &name, const string &surname, const string & address):
    name(name), surname(surname), address(address) {}

    Person::Person(std::istream &in)
{
    read(in, *this);
}

std::ostream & print(std::ostream &out, const Person &person)
{
    out << person.name << " " << person.surname << " @ " << person.address << std::endl;
    return out;
}

std::istream & read(std::istream &in, Person &person)
{
    in >> person.name >> person.surname >> person.address;
    return in;
}
