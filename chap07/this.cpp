#include <iostream>
#include <string>

struct employee
{
    std::string name;
    std::string surname;
    unsigned short id;
    double salary;

    // 1. This function is declared with `const` after the parameter list.
    //    That means it is a const member function:
    //      - The compiler treats `this` as a pointer to const: `const employee* const this`
    //        - First `const` = the object pointed to is read-only (cannot modify members)
    //        - Second `const` = the `this` pointer itself cannot be reassigned
    // 2. Inside the class, member variables are accessed via `this` pointer.
    //    So `return name;` is effectively `return this->name;`.
    // 3. The const ensures that this function does not modify the instance, enforcing encapsulation.
    std::string get_name() const { 
        return name; 
        // this->surname = "Not allowed due to low-level const!"; // prohibited!
    }

    // This function modifies the `name` member, so it cannot be const.
    void set_name(const std::string& new_name) { 
        name = new_name; 
    }

    /*  Note also that Every member function defined inside the class is implicitly an inline request.
        The compiler may ignore it, but it can help performance for small functions.
    */

    // Just a member function declaration
    employee& update_salary(double rhs);
    employee update_salary_faulty(double rhs);


};

// The member function definition outside the class
employee& employee::update_salary(double rhs)
{  
    salary+= rhs;
    return *this; // returns a reference to the instance of the class 
    // so we can do things like obj.update_salary(<val>).update_salary(<val>)

    // if not for reference return type, then the outer-most calls would be assigning on temp objects which would be 
    // destroyed right after the call. Only the first would have the wanted effect
}

employee employee::update_salary_faulty(double rhs)
{
    // current salary is correctly updated but...
    salary+= rhs;
    return *this; // returns a copy of the instance of the class!
    // as mentioned above chaining this function with itself doesn't have an effect.
}

int main()
{

    employee Jack = {"Jack", "Smithereen", 1681, 2000.0};
    
    Jack.update_salary(100.0).update_salary(50.0);
    std::cout << Jack.salary << std::endl; //expect 2150.0
    Jack.update_salary_faulty(50.0).update_salary_faulty(100.0); // second one doesn't have an effect
    std::cout << Jack.salary << std::endl; // expect 2200.0, not 2300.0

    return 0;
}