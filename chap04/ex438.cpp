#include <iostream>

int main()
{
    int j = 20;
    int i = 15;

    double slope = static_cast<double>(j/i);

    /*
    Probably not what the author intended to do here. integer divison of 2 ints converted to double.
    What he intended most probably to do is:
    */
   double slop = static_cast<double>(j)/i; 
   /*
   In this scenario, we explicitly widen int j to double type. then we have the expression j / i which must
   be evaluated before the = operator. Here we have a type missmatch. double / int. The int must be converted
   (implicitly) to a double too. Hence the result will be a double value;
   */

    return 0;
}