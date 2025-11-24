#include <iostream>
#include <string>
using std::string;

int main()
{
	/* 
	Heap memory management with 'new' and 'delete':
	- 'new' allocates an object on the heap and returns a pointer.
	- 'delete' frees a heap object.
	- By default, heap objects themselves are unnamed; you access them via pointers.
	*/

	// 1 Ways of initializing with new

	// Default initialization (uninitialized for built-ins)
	int *p1 = new int;    // value is indeterminate (garbage)
	int *p2 = new int();  // value-initialized → 0

	// Direct initialization
	int *p3 = new int(1024); 

	// List initialization
	int *p4 = new int{1024}; 

	std::cout << "*p1: " << *p1 << "\n"; // garbage
	std::cout << "*p2: " << *p2 << "\n"; // 0
	std::cout << "*p3: " << *p3 << "\n"; // 1024
	std::cout << "*p4: " << *p4 << "\n"; // 1024

	// 2 Auto usage
	auto ap1 = new auto(1024);   // OK, type deduced: int*
	// Note: 'new auto{1024}' is invalid in standard C++ (cannot deduce from brace list with multiple elements)

	std::cout << "*ap1: " << *ap1 << "\n";

	// 3 Const objects

	const int *cp1 = new const int{42}; // pointer to const int (low-level const)
	const int *cp2 = new const int();   // also ok BUT, we now have a memory leak. int 42 is no longer accessible...
	cp1 = cp2;                          // ok, pointer itself is not const (top-level is non-const)

	const int *const cp3 = new const int(123); // const pointer to const int
	// cp3 = cp2; // Error: cp3 is const pointer (top-level const)

	// 4 Deleting dynamically allocated objects
	delete p1; 
	delete p2;
	delete p3;
	delete p4;
	delete ap1;
	delete cp1; // deletes the object originally at cp2
	// delete cp2; CAREFUL! Look at line 41. This would cause a double free ! ERROR!
	delete cp3;

	/*
	Rules for delete:
	- The pointer must either be:
		1. nullptr, or
		2. pointer returned by new
	- Deleting a pointer to a stack variable → undefined behavior
	*/

	int a = 5;
	int *pa = &a;
	// delete pa; // UB! Cannot delete pointer to stack object

	// 5 Again, not your typical pointer behavior!
	int p = 42;
	auto ptr = new auto(p);
	(*ptr)++;
	std::cout << p <<  " vs " << *ptr << std::endl; 

	// Similar to smart pointers, the value bound to ptr by new has nothing
	// to do with the value that was used to initialize it and create it.


/*                             
   __ _ _ __ _ __ __ _ _   _ ___ 
  / _` | '__| '__/ _` | | | / __|
 | (_| | |  | | | (_| | |_| \__ \
  \__,_|_|  |_|  \__,_|\__, |___/
                        __/ |    
                       |___/       
*/

	// 6.1 Simple array of ints
	int n = 5;
	int *arr1 = new int[n];       // default initialization (garbage values for built-ins)
	for(int i = 0; i < n; ++i) arr1[i] = i*10;

	std::cout << "arr1: ";
	for(int i = 0; i < n; ++i) std::cout << arr1[i] << " ";
	std::cout << "\n";

	// 6.2 Value-initialized array
	int *arr2 = new int[n]();    // all elements initialized to 0
	std::cout << "arr2: ";
	for(int i = 0; i < n; ++i) std::cout << arr2[i] << " ";
	std::cout << "\n";

	// 6.3 Array of objects (std::string)
	string *strArr = new string[3];   // 3 empty strings
	strArr[0] = "Hello";
	strArr[1] = "Heap";
	strArr[2] = "World";

	std::cout << "strArr: ";
	for(int i = 0; i < 3; ++i) std::cout << strArr[i] << " ";
	std::cout << "\n";

	// 6.4 Using const with arrays
	const int *constArr = new const int[4]{1, 2, 3, 4}; // array of const ints
	std::cout << "constArr: ";
	for(int i = 0; i < 4; ++i) std::cout << constArr[i] << " ";
	std::cout << "\n";

	// 6.6 Deleting heap arrays [] IS MANDATORY!
	delete[] arr1;
	delete[] arr2;
	delete[] strArr;
	delete[] constArr;

	return 0;
}