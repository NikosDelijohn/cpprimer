#include <iostream>


class Base {};
class Base2: public Base {};

// --- Deriving from Base 2  to D in various ways ---
class PubDeriv: public Base2 {friend void pub_friend(Base*, PubDeriv &);};
class ProtDeriv: protected Base2 { friend void prot_friend(Base*, ProtDeriv &); };
class PrivDeriv: Base2 {friend void priv_friend(Base*, PrivDeriv &);}; // default inheritance access level is priv for class
    void pub_friend(Base* ptr, PubDeriv &ref) { ptr = &ref; }
    void prot_friend(Base* ptr, ProtDeriv &ref) { ptr = &ref; }
    void priv_friend(Base* ptr, PrivDeriv &ref) { ptr = &ref; }

// --- Deriving Further down from D --- 
class  PubDerivDeriv: public PubDeriv  { friend void  pub_deriv_friend(Base*, PubDerivDeriv&); };
class ProtDerivDeriv: public ProtDeriv { friend void prot_deriv_friend(Base *, ProtDerivDeriv &); };
class PrivDerivDeriv: public PrivDeriv { friend void priv_deriv_friend(::Base *, PrivDerivDeriv &);};

    void pub_deriv_friend(Base *ptr, PubDerivDeriv & ref) { ptr = &ref; }
    void prot_deriv_friend(Base *ptr, ProtDerivDeriv &ref) { ptr = &ref; }
    void priv_deriv_friend(Base *ptr, PrivDerivDeriv &ref) { ptr = &ref; } // ERROR: See C case!

int main()
{
    Base* ptr;
    PubDeriv pub_deriv;
    ProtDeriv prot_deriv;
    PrivDeriv priv_deriv;
    PubDerivDeriv pub_deriv_deriv;
    ProtDerivDeriv prot_deriv_deriv;
    PrivDerivDeriv priv_deriv_deriv;

/*
               
     /\     : Converting from usercode! User code MAY  use the conversion ONLY IF 
    /  \      Derived inherits publicly from Base class. If the inheritance chain from Base 
   / /\ \     down to the “branching” base (Base2) is public, that segment preserves the
  / ____ \    ability to convert from descendants of Base2 provided  those descendants also
 /_/    \_\   use public inheritance. If any step becomes protected or private, user code loses 
              that implicit conversion at that point.
*/
    ptr = &pub_deriv; 
    // This is in error because Derived inherits via protected from Base class.
    ptr = &prot_deriv;
    // This is in error because Derived inherits via private from Base class.
    ptr = &priv_deriv;

/*
  ____  
 |  _ \  : Friends or Members of Derived can use the conversion to Base regardless
 | |_) |   of how Derived inherits from base. Either protected or private will work.
 |  _ <  
 | |_) |
 |____/      

*/

    prot_friend(ptr, prot_deriv);
    priv_friend(ptr, priv_deriv);
    pub_friend(ptr, pub_deriv);

/*
   _____ 
  / ____| : Friends or Member functions of classes derived FURTHER from D may use the
 | |        derived-to-base conversion IFF D inherits from B either using public or protected.
 | |        If D inherits using private then the conversion is NOT possible.
 | |____ 
  \_____|

*/
    pub_deriv_friend(ptr, pub_deriv_deriv);
    prot_deriv_friend(ptr, prot_deriv_deriv);

    // ERROR, D inherits privately from Base.
    priv_deriv_friend(ptr, priv_deriv_deriv);

    return EXIT_SUCCESS;
}