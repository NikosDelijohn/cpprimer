#include <iostream>


// 1. DEFAULT CONSTRUCTOR DELETED
// A const member whose type has no default constructor
struct A_no_default 
{
    A_no_default(int) {} // no A_no_default()
};


struct B_default_deleted 
{
    const A_no_default a; // cannot be default-initialized --> default ctor deleted
};


// 2. DEFAULT CONSTRUCTOR DELETED
// A reference member without an in-class initializer
struct C_default_deleted 
{
    int &r; // must be initialized, but default ctor cannot bind it
};


// 3. COPY CONSTRUCTOR DELETED
// Member with deleted copy constructor
struct D_copy_deleted_member 
{
    D_copy_deleted_member() = default;
    D_copy_deleted_member(const D_copy_deleted_member&) = delete;
};


struct E_copy_ctor_deleted 
{
    D_copy_deleted_member m; // copy-ctor deleted because member is non-copyable
};


// 4. COPY-ASSIGNMENT DELETED
// A const member prevents copy assignment
struct F_copy_assign_deleted 
{
    const int x = 0; // const member cannot be reassigned
// synthesized operator= is deleted
};


// 5. COPY-ASSIGNMENT DELETED
// A reference member prevents copy assignment
struct G_copy_assign_deleted 
{
int &r; // cannot rebind reference in operator=
    G_copy_assign_deleted(int &rr) : r(rr) {}
};


// 6. DESTRUCTOR DELETED
// Destructor deleted because a member has deleted destructor
struct H_dtor_deleted_member 
{
    ~H_dtor_deleted_member() = delete;
};


struct I_dtor_deleted 
{
    H_dtor_deleted_member m; // synthesized ~I deleted because m's dtor is deleted
};


int main() 
{
    return EXIT_SUCCESS;
}