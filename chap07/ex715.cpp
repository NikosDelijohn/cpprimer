#include <iostream>
#include <string>
using std::string;

struct Person;
std::ostream &print(std::ostream &, const Person &);
std::istream &read(std::istream &, Person &);

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

    Person() = default;
    Person(const string &name, const string &surname, const string & address):
        name(name), surname(surname), address(address) {}
    Person(std::istream &in)
    {
        read(in, *this);
    }
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

int main()
{
    Person Mike(std::cin);

    std::cout << Mike.name << " " <<  Mike.surname << " " << Mike.address << std::endl;

    return EXIT_SUCCESS;
}

