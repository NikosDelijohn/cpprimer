#include "declarations_and_definitions.hpp"

int main()
{
    some_function(1,2); // ok 
    // some_problematic_function(1,2); // but this is wrong! missmatch between prototype and definition!
    /*
declarations_and_definitions_main.cpp: In function ‘int main()’:
declarations_and_definitions_main.cpp:6:34: error: too many arguments to function ‘int some_problematic_function(int)’
    6 |     some_problematic_function(1,2);
      |                                  ^
In file included from declarations_and_definitions_main.cpp:1:
declarations_and_definitions.hpp:5:5: note: declared here
    */

    return 0;
}