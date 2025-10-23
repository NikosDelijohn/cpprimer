#include <iostream>
#include <string>
using std::string;

int main()
{

    int i; double d; const string *ps; char *pc; void *pv;

    // pv = (void *)ps;
    pv = static_cast<void *>(const_cast<string *>(ps)); // or 
    pv = const_cast<void *>(static_cast<const void*>(ps));

    // i = int(*pc)
    i = static_cast<int>(*pc);

    // pv = &d; no cast takes place here. void can point to any type. nothing to do.

    // pc = (char* ) pv;
    pc = static_cast<char *>(pv);

    return 0;
}