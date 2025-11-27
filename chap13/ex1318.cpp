#include <iostream>
#include <string>

class Employee
{
public:
    Employee():
        name(),
        id(seed++)
    {}
    
    Employee(std::string name):
        name(name),
        id(seed++)
    {}

    void print()
    {
        std::cout << name << ": " << id << std::endl;
    }
private:
    std::string name;
    size_t id;
    static size_t seed;
};

size_t Employee::seed = 0;

int main()
{
    Employee bob("Bob");
    Employee alice("Alice");

    bob.print();
    alice.print();
    
    return EXIT_SUCCESS;
}