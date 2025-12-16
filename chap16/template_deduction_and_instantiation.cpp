#include <iostream>

// Template function to compare two values using < operator
template <typename T>
bool compare(const T& a, const T& b) 
{
    return a < b;
}

int main() 
{
    int x = 5, y = 10;
    double dx = 3.14, dy = 2.71;

    std::cout << compare(x, y) << std::endl;  // instantiates compare<int>
    std::cout << compare(dx, dy) << std::endl; // instantiates compare<double>
}

/*
Explanation of compiler template deduction and instantiation:

1. Template Declaration:
   template <typename T>
   bool compare(const T& a, const T& b)
   - T is a placeholder for a type.

2. Function Call with int:
   compare(x, y)
   - x and y are of type int.
   - Compiler deduces T = int.
   - Instantiates a function compare<int>(const int&, const int&).

3. Function Call with double:
   compare(dx, dy)
   - dx and dy are of type double.
   - Compiler deduces T = double.
   - Instantiates compare<double>(const double&, const double&).

4. Rules of deduction:
   - Compiler looks at the arguments passed and matches them to the template parameters.
   - Only instantiates the template for types that are actually used.

5. Compilation result:
   - The template code exists generically, but only the needed instantiations (compare<int> and compare<double>) are generated in the binary.
*/