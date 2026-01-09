#include <iostream>
#include <utility>   // std::move

// ============================================================
// decltype COMPLETE EXAMPLES
// ============================================================
//
// Core rules:
//
// 1) decltype(unparenthesized-id-expression)
//    → declared type (keeps const, keeps reference)
//
// 2) decltype(lvalue-expression)   → T&
// 3) decltype(xvalue-expression)   → T&&
// 4) decltype(prvalue-expression)  → T
//
// auto (contrast):
// - drops top-level const
// - drops references unless auto& / auto&& is used
//

int global = 0;

int func(int x) { return x; }

struct S {
    int m;
    int& get_ref() { return m; }
};

int main()
{
    // --------------------------------------------------------
    // CONST and REFERENCES
    // --------------------------------------------------------
    const int ci = 42;
    const int& cir = ci;

    decltype(ci) a = 0;        // const int
    auto b = ci;               // int (top-level const dropped)

    decltype(cir) c = a;       // const int&
    auto d = cir;              // int
    auto& e = cir;             // const int&

    // --------------------------------------------------------
    // ID-EXPRESSION vs PARENTHESIZED EXPRESSION
    // --------------------------------------------------------
    int value = 1;
    int& ref = value;

    decltype(value) v1 = 0;    // int
    decltype((value)) v2 = value; // int&

    decltype(ref) r1 = value; // int& (declared type)
    decltype((ref)) r2 = value; // int& (lvalue expression)

    // --------------------------------------------------------
    // LVALUE / PRVALUE / XVALUE
    // --------------------------------------------------------
    decltype(42) p1 = 42;          // int (prvalue)
    decltype(value + 1) p2 = 2;   // int (prvalue)

    decltype((value)) l1 = value; // int& (lvalue)

    decltype(std::move(value)) x1 = 3; // int&& (xvalue)

    // --------------------------------------------------------
    // ARRAYS
    // --------------------------------------------------------
    int arr[4] = {1,2,3,4};

    auto a_arr = arr;              // int* (decays)
    decltype(arr) d_arr = {1,2,3,4}; // int[4]
    decltype((arr)) r_arr = arr;   // int (&)[4]

    // --------------------------------------------------------
    // POINTERS
    // --------------------------------------------------------
    int* p = &value;

    decltype(p) p1d = p;           // int*
    decltype((p)) p2d = p;         // int*&

    // --------------------------------------------------------
    // FUNCTIONS
    // --------------------------------------------------------
    decltype(func) f1 = func;      // int(int)
    decltype(&func) f2 = func;     // int (*)(int)

    auto f3 = func;                // int (*)(int)

    // --------------------------------------------------------
    // STRUCT MEMBERS
    // --------------------------------------------------------
    S s{10};

    decltype(s.m) m1 = 0;          // int
    decltype((s.m)) m2 = s.m;      // int&

    decltype(s.get_ref()) m3 = s.m;   // int& (returns ref)
    decltype((s.get_ref())) m4 = s.m; // int&

    // --------------------------------------------------------
    // GLOBALS
    // --------------------------------------------------------
    decltype(global) g1 = 0;        // int
    decltype((global)) g2 = global; // int&

    // --------------------------------------------------------
    // AUTO vs DECLTYPE SUMMARY
    // --------------------------------------------------------
    const int cx = 5;
    const int& crx = cx;

    auto ax1 = cx;         // int
    auto ax2 = crx;        // int
    auto& ax3 = crx;       // const int&

    decltype(cx) dx1 = 0;  // const int
    decltype(crx) dx2 = cx; // const int&
    decltype((cx)) dx3 = cx; // const int&

    // --------------------------------------------------------
    // LAMBDAS
    // --------------------------------------------------------
    auto lambda = [](int x) { return x + 1; };

    decltype(lambda) lam1 = lambda;   // closure type
    auto lam2 = lambda;               // same closure type

    // --------------------------------------------------------
    // AUTO&& vs DECLTYPE
    // --------------------------------------------------------
    auto&& u1 = value;            // int&  (universal reference)
    auto&& u2 = 5;                // int&&

    decltype(auto) da1 = (value); // int&
    decltype(auto) da2 = value;   // int
    decltype(auto) da3 = std::move(value); // int&&

    return 0;
}
