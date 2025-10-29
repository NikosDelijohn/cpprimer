#include <iostream>

void manip(int a, int b) { ;}

int main()
{
    double dobj;

    manip('a','z'); 
    /*
    Ranking.
        1) Exact match? NO
        2) Const conversion? NO
        3) Match through promotion? YES, chars are promoted to int
    */

    manip(55.4, dobj);
    /*
    Ranking.
        1) Exact match? NO
        2) Const conversion? NO
        3) Match through promotion? NO
        4) Match through arithmetic conversion? YES, doubles are narrowed down to ints.
    */

    return 0;
}