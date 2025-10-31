#ifndef _EX722_
#define _EX722_

#include <iostream>
#include <string>

class Person;
std::ostream &print(std::ostream &, const Person &);
std::istream &read(std::istream &, Person &);

class Person
{
    friend std::ostream &print(std::ostream &, const Person &);
    friend std::istream &read(std::istream &, Person &);

public:
    // inline is missing here: get_name is implicitly inlined because its DEFINED
    std::string get_name() const { return name;}
    
    // function is explicitly declared as inline. DEFINITION must happen in the SAME FILE
    inline 
    std::string get_surname() const;

    // function is not declared inline. Can become inline later !
    std::string get_address() const;

    Person();
    Person(const std::string &, const std::string &, const std::string &);
    Person(std::istream &);

private:
    std::string name;
    std::string surname;
    std::string address;
};

std::string Person::get_surname() const
{
    return surname; // or
    // return this->surname; // this is:  const Person *const this (top and low-level const pointer)
}

// get_address is now inline!
inline
std::string Person::get_address() const
{
    return this->address;
}


#endif