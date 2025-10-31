#include <iostream>
#include <string>

struct a_struct
{
    int struct_value_a = 0;
    int struct_value_b = 1;
};

class a_class
{
    // friend std::ostream &show(a_class &); // can be also placed here  

    int class_value_a = 2;
    int class_value_b = 3;

    friend std::ostream &show(a_class &); 
};

std::ostream &show(a_class &obj)
{
    std::cout << obj.class_value_a << ", " << obj.class_value_b;
    return std::cout;
}

class class_with_typealias
{
public:
    // type aliases must be defined before other members 
    typedef std::string::size_type sz_t;
    using sz_ut = std::string::size_type; // equivalent

    std::string cwt_str_a;
    int cwt_val_a = 0;
    sz_t cwt_val_b = 0u;

    mutable int ctw_mutable_int = 0;

    void print_mutable_and_increment() const
    {
        std::cout << ctw_mutable_int << std::endl;
        ++ctw_mutable_int; // How? Because of mutable

        // the function promises to not alter the state of the object with const (adds low-level constness to `this`)
        // but the fact that the member is mutable permits for const functions 
        // to modify them

        //++cwt_val_a; // this is not mutable, cant do!! 
    }

};

int main()
{
    a_struct struct_obj = {};
    a_class class_obj = {};

    // The only difference is the default access level.
    // for struct, if no access specifiers are defined
    // everything is public!
    std::cout << struct_obj.struct_value_a << ", " << struct_obj.struct_value_b << std::endl; // Expect 0, 1

    // for class, if no access specifiers are defined
    // everything is private!
    
    // std::cout << class_obj.class_value_a << ", " << class_obj.class_value_b << std::endl; // wrong!
    // compiling gives: error: ‘int a_class::class_value_a’ is private within this context
    //                  error: ‘int a_class::class_value_b’ is private within this context


    // One solution, tailored specifically to functions or other classes EXTERNAL to our class
    // is the friend. A friendly class can access the private members. Must be declared as friendly
    // as shown in line 15. Either at the beginning or the end of the class (doesn't matter).

    // However, this is NOT A GENERAL DECLARATION. The function is declared at the scope of the class
    // and is accessible only within the class. To make it accessible to other parts of the code the 
    // friend function must be re-declared. In the current file it is not only declared but defined so
    // it works as expected but if we move it after main, the same rules apply as with any function. 
    // Must be either defined before the code reaches the part where the function is called or
    // declared before the code reaches the part where the function is called
    show(class_obj) << std::endl;

    // I can refer to the aliased type using the scope oper
    class_with_typealias::sz_t value; // and not
    //sz_t value; // sz_t is not found in current scope!
    class_with_typealias cwt_object;
    cwt_object.print_mutable_and_increment(); // expect 0
    cwt_object.print_mutable_and_increment(); // expect 1


    return 0;

}

/* When we intend to have a data class with all the members public -> struct. Class otherwise */