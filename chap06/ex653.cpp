// (A)
int calc(int&, int&);
int calc(const int&, const int&);

/*
Diferences are that the calc(int&, int&) can accept only noncost int arguments, whereas
calc(const int&, const int&) can accept both noncost and const arguments and also temporaries (rvalues)
*/

// (B)
int calcB(char*, char*);
int calcB(const char*, const char*);
/*
Similar to (A)
calcB(char*, char*) can accept only noncost char type pointees, whereas
calc(const char*, const char*) can accept both noncost and const arguments
*/

// (C)
int calcC(char*, char*);
int calcC(char* const, char* const);
/*
The calcC(char*, char*) accepts addresses of non-cost char objects.
The calcC(char *const, char *const) variant accepts addresses of non-cost char objects too.
The top level const that it imposses says nothing about the constness of the underlying (pointee) object.
Hence these calls are practically equivalent when it comes ot function mathching. The only difference 
which is immaterial judging from the return type, is that these two parameters cannot be re-assigned within
the function's body. 
*/