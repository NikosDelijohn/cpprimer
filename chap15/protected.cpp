
/*
    Protected members are inaccessible to USERS of the class.
    Protected members are accessible to members and friends of classes derived from this class.
    
    A derived class member or friend may access the protected members of the base class ONLY through a derived member. // see line 50
    The derived class has no special access to the protected members of base-class objects. // see line 26

*/

class Base
{
protected:
    int prot_mem = 0;
};

class Sneaky: public Base
{
    friend void clobber(Sneaky &);
    friend void clobber(Base &);
    int j = Base::prot_mem; // derived class Can access Base protected 

    void f(Sneaky &d, Base &b) {
        this->prot_mem = 1;  // OK: accessing own Base subobject
        d.prot_mem = 2;      // OK: accessing Base subobject of another Derived
        b.prot_mem = 3;      // ERROR: can't access protected in a plain Base object
    }
};

void clobber(Sneaky &s)
{   
    /*
    A friend of a publicly derived class can access 
    protected members THROUGH the derived class!
    */
    s.j = s.prot_mem = 0; 
}

void clobber(Base &b)
{
    /*
    clobber is not a friend of Base nor it has 
    a derived class to access a protected member! 
    Thus it cannot access a protected member even though
    it is a friend of a derived class.

    Being a friend of Sneaky does not make a function a friend of Base.

    */
    b.prot_mem = 5;
}