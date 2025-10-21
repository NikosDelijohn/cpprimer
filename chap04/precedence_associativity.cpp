#include <iostream>

int a(){return 1;}
int b(){return 1;}
int c(){return 1;}
int d(){return 1;}

int main()
{
    /* Precedence: the order in which the operators are grpouped (NOT EVALUATED). e.g.,
                   in arithmetic context, * and / have higher precedence than + and - 
    Associativity: determines how to group operands with the same precedence.
    
    Arithmetic operators are LEFT-ASSOCIATIVE: Operators at the same precedence group left to right
    Input Output operators are LEFT-ASSOCIATIVE.
    
    */

    // Compound expression: an expression with >1 operators

    std::cout << 3 + 4 * 5 << std::endl; // its 23 and not 35 (precedence of * oper)
    std::cout << 20-15-3 << std::endl; // its 2 and not 8 (associativity)

    // a snippet with undefined behavior
    int i = 0;
    std::cout << i << " " << ++i << std::endl;

    /* we know that ++val (prefix increment) has higher precedence than << (left bitwise shift) 
    however it is unclear whether the compiler will EVALUATE the ++ first or after the print statement.
    hence it may print 0 0 or it may print 1 1 or 0 1 or something else -> UNDEFINED behavior!
    
    THE ONLY OPERATORS THAT GUARANTEE AN ORDER OF EVALUATION ARE:
        && logical and: guarantess that the lhs oper is evaluated first and that the rhs operand is 
                        evaluated ONLY if the lhs evaluates to true -> short circuit evaluation
        
        || locical  or: guarantees that the lhs oper is evaluated first and that the rhs operand is 
                        evaluated ONLY if the lhs evaluates to false -> short circuit evaluation

     (? :) conditional  
    
     , comma
    
     */

     // all together: evaluation, precedence, associativity

    std::cout << a() + b() * c() + d() << std::endl;

    //    Precedence: guarantees that the results of b() and c() are multiplied
    // Associativity: guarantees that the result of a() is added to the product of b() and (c) 
    //                and that the result of that addition is added to the value returned by d()
    //    Evaluation: there are NO GUARANTEES for the order in which the functions are called.

    // IF all thse functions are independent meaning that they:
    //      (i) do not affect the state of the same objects 
    //      (ii) perform IO
    // then the order in which they are evauluated is irrelevant.
    // if any of these functiosn DO affect the same object, then the expression has undefined behavior and 
    // it is in error!!


    std::cout << -21 % 5 << std::endl;

    return 0;
}