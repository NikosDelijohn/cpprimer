#include <iostream>
#include <vector>
#include <array>
using std::array;
using std::vector;

/*
Excluding std::string, AND std::array

swapping sequential containers does NOT invalidate references and pointers, and thus iterators.
it just re-arranges containers' internal values and pointers. Very fast operation!
            
STACK             HEAP

             MEM Addr A            MEM Addr B
                  +----------------+
seq1 ------------>| A, B, C, D, E, |
                  +----------------+
                  |begin1          |end1
               
             MEM Addr C            MEM Addr D
                  +----------------+
seq2 ------------>| F, G, H, I, J, | 
                  +----------------+
                  |begin2          |end2
             
             ======== AFTER SWAP ========
             
             MEM Addr A           MEM Addr B
                  +----------------+
seq1 -+   +------>| A, B, C, D, E, |
      |   |       +----------------+
      |   |       |begin1          |end1 <- careful here! iterators are unchanged!
      |   |     
      |   |  MEM Addr C            MEM Addr D
      |   |       +----------------+
seq2 -|---+  +--->| F, G, H, I, J, | 
      +------+    +----------------+
                  |begin2          |end2
             
*/

int main()
{
    vector<int> vec1 {1,2,3,2,1};
    vector<int> vec2 {7,6,5,4,5,6,7};

    auto v1beg = vec1.begin();
    auto v2beg = vec2.begin();

    std::cout << "ADDRESS(vec1[0]): " << &vec1[0] << std::endl;
    std::cout << "ADDRESS(vec2[0]): " << &vec2[0] << std::endl;

    std::cout << "\tvec1[0]:" << vec1[0] << " == " << "*v1beg: " << *v1beg << " != vec2[0]: " << vec2[0] << std::endl;
    std::cout << "\tvec2[0]:" << vec2[0] << " == " << "*v2beg: " << *v2beg << " != vec1[0]: " << vec1[0] << std::endl;
    
    std::swap(vec1,vec2);

    // Base adresss of elements is swapped.
    std::cout << "ADDRESS(vec1[0]): " << &vec1[0] << std::endl;
    std::cout << "ADDRESS(vec2[0]): " << &vec2[0] << std::endl;
    
    // However, the pre-existing pointers (iterators) remain unchanged.
    std::cout << "\tvec1[0]:" << vec1[0] << " != " << "*v1beg: " << *v1beg << " == vec2[0]: " << vec2[0] << std::endl;
    std::cout << "\tvec2[0]:" << vec2[0] << " != " << "*v2beg: " << *v2beg << " == vec1[0]: " << vec1[0] << std::endl << std::endl << std::endl;

/*
                                    
     /\                             
    /  \   _ __ _ __ __ _ _   _ ___ 
   / /\ \ | '__| '__/ _` | | | / __|
  / ____ \| |  | | | (_| | |_| \__ \
 /_/    \_\_|  |_|  \__,_|\__, |___/
                           __/ |    
                          |___/     
*/

    /*
    Arrays are not storing elements in the heap. They are of fixed size and stored in the stack.
    Swap behaves differently here. Swapping does not modify internal data, it swaps EVERY element
    with the corresponding one. Hence, its slow especially for large arrays.

STACK             STACK

             MEM Addr A            MEM Addr B
                  +----------------+
seq1 ------------>| A, B, C, D, E, |
                  +----------------+
                  |begin1          |end1
               
             MEM Addr C            MEM Addr D
                  +----------------+
seq2 ------------>| F, G, H, I, J, | 
                  +----------------+
                  |begin2          |end2
             
        ======== AFTER SWAP ========
             
             MEM Addr A           MEM Addr B
                  +----------------+
seq1 ------------>| F, G, H, I, J, | 
                  +----------------+
                  |begin1          |end1 
     
             MEM Addr C            MEM Addr D
                  +----------------+
seq2 ------------>| A, B, C, D, E, |
                  +----------------+
                  |begin2          |end2

    */

    array<int, 5> arr1 = {1,2,3,4,5};
    array<int, 5> arr2 = {6,7,8,9,10};

    auto arr1beg = arr1.begin();
    auto arr2beg = arr2.begin();

    std::cout << "ADDRESS(arr1[0]): " << &arr1[0] << std::endl;
    std::cout << "ADDRESS(arr2[0]): " << &arr2[0] << std::endl;

    std::cout << "\tarr1[0]:" << arr1[0] << " == " << "*arr1beg: " << *arr1beg << " != arr2[0]: " << arr2[0] << std::endl;
    std::cout << "\tarr2[0]:" << arr2[0] << " == " << "*arr2beg: " << *arr2beg << " != arr1[0]: " << arr1[0] << std::endl;
    
    std::swap(arr1,arr2);

    std::cout << "ADDRESS(arr1[0]): " << &arr1[0] << std::endl;
    std::cout << "ADDRESS(arr2[0]): " << &arr2[0] << std::endl;

    std::cout << "\tarr1[0]:" << arr1[0] << " == " << "*arr1beg: " << *arr1beg << " != arr2[0]: " << arr2[0] << std::endl;
    std::cout << "\tarr2[0]:" << arr2[0] << " == " << "*arr2beg: " << *arr2beg << " != arr1[0]: " << arr1[0] << std::endl;

    return EXIT_SUCCESS;
}