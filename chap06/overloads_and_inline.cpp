#include <iostream>
#include <string>
#include <cctype>
using std::string;

const string &shorter_str(const string &s1, const string &s2)
{   
    std::cout << "\t1" << std::endl;
    return s1.size() <= s2.size() ? s1 : s2;
}

string &shorter_str(string &s1, string &s2)
{
    std::cout << "\t2" << std::endl;
    //   & required because auto discards top-level consts!
    auto &r = shorter_str(const_cast<const string&>(s1), 
                          const_cast<const string&>(s2));
    //     safe to remove const because r refers to one of the two original nonconst objects
    return const_cast<string&>(r);
}

inline string &
the_shorter_string(string &s1, string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

// function matching examples //
void ff(int a) { std::cout << "ff(int)" << std::endl;}
void ff(short a) { std::cout << "ff(short)" << std::endl;}

void manip(long b) { std::cout << "ff(long)" << std::endl;}
void manip(float b) { std::cout << "ff(float)" << std::endl;}

int main()
{
    string s1 = {"smaller"}, s2 = {"greater!"};
    string res = shorter_str(s1,s2); // this is a copy-initialization of res.
    // shorter_str (2) is called which returns a reference to one of its arguments.
    // however the type of res is string not string&. Hence, a call to the appropriate
    // string class copy constructor is happening under the hood that tries to match the arg str&
    // to generate a str object. res is practically a seperate copy of the reference returned
    // by shorter_str(2) and not the reference itself.
    
    for (char &ch: res)
        ch = std::toupper(ch);
    
    std::cout << "res: " << res << " s1:" << s1 << std::endl; 

    string &res_2 = shorter_str(s1,s2);
    for (char &ch: res_2)
        ch = std::toupper(ch);
    
    std::cout << "res: " << res_2 << " s1:" << s1 << std::endl;
    
    // smalls functions like these that may be used often are a good construct.
    // One, 'centralized' part where the computation happens -> easy to maintain
    // Two, well defined behavior indicated by a human-readable function name,
    //      indicative of what the function will do rather than inferring what
    //      is actually happening by evaluating the conditional or the func logic
    // One drawback however, is the function call which is a costly operation in
    // terms of assembly lines. Registers saved, then restored etc.
    //
    // Inline solves this issue by ASKING the compiler IF POSSIBLE (!) to expand
    // the function at call-time and ommit a function call. The compiler however,
    // may choose to ignore this request! 
    //
    // Inline is ment to optimize small, straight-line functions that are called
    // frequently!

    // this will be expanded
    auto &res_3 = the_shorter_string(s1, s2);
    /*
        1. Compile with g++ -S overloads_and_inline.cpp -o out.S
        2. Open in IDE the out.S assembly file
        3. Search for "the_shorter_string" string in the assembly
        4. If NOT found, function call was expanded successfully!    
    */

    /*
  ______                  __  __       _   _          _             
 |  ____|                |  \/  |     | | | |        (_)            
 | |__ _   _ _ __   ___  | \  / | __ _| |_| |__   ___ _ _ __   __ _ 
 |  __| | | | '_ \ / __| | |\/| |/ _` | __| '_ \ / __| | '_ \ / _` |
 | |  | |_| | | | | (__  | |  | | (_| | |_| | | | (__| | | | | (_| |
 |_|   \__,_|_| |_|\___| |_|  |_|\__,_|\__|_| |_|\___|_|_| |_|\__, |
                                                               __/ |
                                                              |___/ 
    */

    /* The ranking is the following 
        1. Exact Match; Happens when
            - The argument and parameter types are identical
            - The argument is converted from an array or function type 
              to the corresponding pointer type. (ex. pointer decay)
            - A top-level const is added to OR discarded from the argument
        2. Match through const conversions
        3. Match through promotions (integral types)
        4. Match through an arithmetic or pointer conversion
        5. Match through a class-type conversion
    
    */
    
    ff('a'); // although char is closest to short characters promote to integers! hence ff(int) will be called!
    // As a matter of fact, ff(short) will ONLY be called for EXACT matches. i.e, arg is short
    short a = 12;
    ff(a); // exact match ff(short) is called.

    // similarly, 
    //manip(3.14); // 3.14 is a DOUBLE literal. Hence it needs to be narrowed to either long or float. Since there are 2 possible conversions its ambiguous!
    // but 
    manip(3.14f); // 3.14f is a FLOAT literal! This is fine. manip(float) is called.
}