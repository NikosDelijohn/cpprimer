class Base {};
struct Pub_Derv : public Base { void memfcn(Base &b) { b = *this; } };
struct Priv_Derv : private Base { void memfcn(Base &b) { b = *this; } };
struct Prot_Derv : protected Base { void memfcn(Base &b) { b = *this; } };
struct Derived_from_Public : public Pub_Derv { void memfcn(Base &b) { b = *this; } };
struct Derived_from_Private : public Priv_Derv { void memfcn(::Base &b) { b = *this; }}; // Not allowed!
struct Derived_from_Protected : public Prot_Derv { void memfcn(Base &b) { b = *this; }};

int main() 
{
    Pub_Derv d1; Priv_Derv d2; Prot_Derv d3;
    Derived_from_Public dd1; Derived_from_Private dd2; Derived_from_Protected dd3;

    // Usercode requires a chain of public inheritance relationships //
    Base *p = &d1; // OK!
    p = &d2;       // NOT OK
    p = &d3;       // NOT OK
    p = &dd1;      // OK!
    p = &dd2;      // NOT OK 
    p = &dd3;      // NOT OK

    return 0;
}