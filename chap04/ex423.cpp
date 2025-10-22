#include <iostream>
#include <string> 
using std::string; 

int main()
{
    string s = "word";
    //string pl = s + s[s.size() -1] == 's' ? "" : "s";
    /*
     Operator precedence is [] > + > == > ?: 
     With that said, the above expression
     - concatenates s with the last character of s 
     - tries to compare the resulting string with a character -> Error no such operator overload exists for str == char
    */
   
    // fix:
    string pl = s + ((s[s.size() -1] == 's') ? "" : "s");

    return 0;
}