#include <iostream>
#include <string>

using std::string;

int main()
{
    // Initialization ways

    string s1; // default init
    string s2 = s1; // copy init
    string s3 = "hiya"; // copy init
    string s4(10, 'c'); // direct init
    string s5("Heyyo!"); // direct init
    
    // Operations
    //string s6 = "hi " + "  bro"; // wrong at least one operand must be a string type (not literal)
    string s7 = s5 + ", " + " world"; // ok because s5 + ", " returns a string type
    return 0;

    // C-Strings and library Strings
    
    // LITERAL STRINGS ARE CONST CHAR* !!
    const char cstr[256] = "Hello!"; // automatically adds '\0' NULL terminator to hello!
    const char cstr2[256] = {'A','B','C'}; // does NOT add '\0' NULL terminator to ABC!!
    //const char cstr3[5] = "Hello" // error! not enough space to add '\0' NULL terminator!!

    string libstr = cstr; // ok, we can initialize a libstr from cstr
    //const char *cstr4 = libstr; // error! we cannot initialize a cstr from a libstr - BUT -
    const char *cstr4 = libstr.c_str(); // this works! c_str() returns a const char *

}