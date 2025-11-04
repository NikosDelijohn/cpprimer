#include <iostream>
#include <string>
#include <vector>

size_t counter()
{   
    // Initialized once, before the 1st execution
    // reaches the line it checks whether var 'cc'
    // is already initialized. If not, it gets 
    // initialized then. Otherwise previous value 
    // is kept and initializer is ignored.
    static size_t cc = 0u;
    return ++cc;
}

/*
   _____ _        _   _        __  __                _                   
  / ____| |      | | (_)      |  \/  |              | |                  
 | (___ | |_ __ _| |_ _  ___  | \  / | ___ _ __ ___ | |__   ___ _ __ ___ 
  \___ \| __/ _` | __| |/ __| | |\/| |/ _ \ '_ ` _ \| '_ \ / _ \ '__/ __|
  ____) | || (_| | |_| | (__  | |  | |  __/ | | | | | |_) |  __/ |  \__ \
 |_____/ \__\__,_|\__|_|\___| |_|  |_|\___|_| |_| |_|_.__/ \___|_|  |___/
                                                                         
                                                                        

*/
// Static members in classes
class static_member_class
// Banking account 
{
public:
    void calculate() { amount += amount * interest_rate; }

    // Statics to set and get private static data members
    static double rate() {return interest_rate;}
    static void rate(double);

    static constexpr int it_will_fail_if_not_defined_outside = 100; // look at line 60. We will use this as an argument to that func
private:
    std::string owner;
    double amount;

    static double interest_rate; // static data members must be defined / initialized OUTSIDE class. Cannot be in-class initialized
    static double init_rate();

    static const int unless_its_const = 42; // however, we CAN provide in class initializers if const.
    static const int another_const; // here we don't provide an in-class initializer (initialized outside class's body)
    static constexpr int or_constexpr = 52; // and we MUST provide in class initializers if constexpr.
};

// defining static member functions
void static_member_class::rate(double new_rate) { interest_rate = new_rate; }
double static_member_class::init_rate() { return 1.0;}
// initializing static data member
double static_member_class::interest_rate = init_rate();
const int static_member_class::unless_its_const; // if initialized inclass, just a declaration here
const int static_member_class::another_const = 43; // not initialized in class, initialzed explicitly here.
constexpr int static_member_class::or_constexpr; // constexpr is initialized in-class. just declaration here.

void some_foo(const int& val)
{
    std::cout << val << std::endl;
}
constexpr int static_member_class::it_will_fail_if_not_defined_outside;

/*

              _   _              _____ _        _   _      
             | \ | |            / ____| |      | | (_)     
 __   _____  |  \| | ___  _ __ | (___ | |_ __ _| |_ _  ___ 
 \ \ / / __| | . ` |/ _ \| '_ \ \___ \| __/ _` | __| |/ __|
  \ V /\__ \ | |\  | (_) | | | |____) | || (_| | |_| | (__ 
   \_/ |___/ |_| \_|\___/|_| |_|_____/ \__\__,_|\__|_|\___|
                                                           
                                                           
*/
class static_vs_nonstatic_members
{
public:
    //static_vs_nonstatic_members non_static; // nope. this is an incomplete type! class is not fully defined yet!
    static_vs_nonstatic_members &non_static; // ok!
    static_vs_nonstatic_members *non_static; // also ok!
    
    static static_vs_nonstatic_members static_dummy; // this is ok!

    // This is also ok! Static members CAN be used as default parameters to member funcs!
    static_vs_nonstatic_members(int val = default_param);

private:
    static int default_param;
};


int main()
{
    for (size_t i = 0u; i != 10; ++i)
        std::cout << counter() << std::endl;
    
    // accessing and invoking static members
    std::cout << static_member_class::rate() << std::endl;
    static_member_class::rate(5.0);
    std::cout << static_member_class::rate() << std::endl;

    static_member_class obj;
    static_member_class &robj = obj;
    // also through refs (and also ptrs)
    std::cout << robj.rate() <<  std::endl;

    some_foo(static_member_class::it_will_fail_if_not_defined_outside);
    // this will compile, however the linker might not be able to find the static (comment line 64)
    /*
    statics.cpp:(.text+0x18a): undefined reference to `static_member_class::it_will_fail_if_not_defined_outside'  
    */

    // So we define it (uncomment line 64) not re-initialize, but declare and re-compile -> works!
    some_foo(static_member_class::it_will_fail_if_not_defined_outside);


    return 0;

}

