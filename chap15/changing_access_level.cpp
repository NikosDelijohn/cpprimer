#include <iostream>

class Base 
{
public:
    void greet() { std::cout << "Hello from Base\n"; }
protected:
    int prot_val = 42;
};

class Derived_Public : private Base 
{
public:
    // Promote specific Base members to Derived's public interface
    // Although we inherited as private, we can change the access level
    // to future classes that will inherit from this. 
    // The using keyword is used in the public part of the Object. Which
    // means that these members are now accessible even to users of the
    // Derived_Public class not only to derived classes and friends.
    using Base::greet;
    using Base::prot_val;
};

class Derived_Protected : private Base 
{

protected:
    // The using keyword is used in the protected part of the Object. Which
    // means that these members are now accessible only to derived classes
    // and friends of this class.
    using Base::greet;
    using Base::prot_val;

    friend void prot_friend(Derived_Protected &obj)
    {
        std::cout << "prot_friend(Derived_Protected &): " <<  obj.prot_val << std::endl;
    }
};

class Derived_Private : private Base
{
    
private:
    // The using keyword is used in the protected part of the Object. Which means
    // that these members are accessible only to members of this class and also friends.
    using Base::greet;
    using Base::prot_val;

    friend void priv_friend(Derived_Private &obj)
    {
        std::cout << "priv_friend(Derived_Private &): " << obj.prot_val << std::endl;
    }
};

class Third : public Derived_Public 
{
public:

    void show() 
    {
        greet(); // greet promoted to public in Derived
        std::cout << prot_val << "\n"; // prot_val promoted too
    }
};


int main() 
{

    // Accessing the private, promoted to public members both as a user and also through the inheritance relationship.
    Third t;
    t.show();   // Output: "Hello from Base" and "42"
    t.greet(); 
    std::cout << t.prot_val << "\n"; // works because prot_val promoted

    // Accessing the private, promoted to protected members!
    Derived_Protected d;
    prot_friend(d);

    // Accessing the private, promoted to private members!
    Derived_Private p;
    priv_friend(p);
}