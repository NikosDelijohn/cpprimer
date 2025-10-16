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
}