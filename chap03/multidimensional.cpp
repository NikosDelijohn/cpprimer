#include <iostream>

int main()
{

    const unsigned short rows = 2, cols = 3, height = 3;

    int array2d [rows][cols]; // the array2d is an array of 2 elements, which are themselves arrays of 3 integers. Default initialized
    int array2d2 [rows][cols] = {
        {1, 1, 3},
        {4, 5, 5}
    }; // list iniitialization of the 2d array

    int array2d3 [rows][cols]{
        {1, 1, 3},
        {4, 5, 5}
    }; // still ok

    int array2d4 [rows][cols] {
        {1},
        {4}
    }; // first element of each nested array is initialized. the rest are VALUE initialized ! (i.e., 0)

    int array2dflat[rows][cols] = { 1,2,3, 4,5,6 }; // also ok, the 'dimensionality' is less visible 

    int array3d[height][rows][cols]; // an array of 3 elements that are arrays of 2 elements which in turn are arrays of 3 integers

    int array3d2[height][rows][cols] = 
    {
        /* h = 0 */
        {
            {1, 2, 3},
            {4, 5, 6}
        },
        /* h = 1*/
        {
            /* r = 0 */
            {7, 8, 9}, /* c = 0 .. 2*/

            /* r = 1 */
            {8, 7, 6}  /* c = 0 .. 2*/
        },
        /* h = 2 */
        {
            {5, 5, 5},
            {6, 3, 4}
        }

    };

    // and the pattern goes on. you can have arrays of arrays of arrays ... 

    // RANGE FOR LOOP !! //

    /*
    Here lies a subtle 'trap' in C++. The following loop is perfectly valid. 
    */
    for (auto &row : array2d2)

        for (auto col : row)
        {
            // do whatever here 
        }

    // But this loop, is not:
    for (auto row: array2d2)

        //for (auto col : row) <-- error here
        {
            // do whatever here
        }

    /* 
    The reason lies behind the auto conversion of arrays into pointers. auto, deduces that the 
    type of row is a pointer to the first element of an array of integers. the inner loop however
    treats the row as an array of objects trying to assing each object to col.
    
    The first loop avoids this by explicitly defining the row to be a reference and not a pointer.
    Hence, on the external loop in the upper set of loops, row is an alias to an array of 'rows' integers and
    on the bootom set of loops, row is a pointer to the first integer of the array.  

    Hence, to use range for with multidimensional  arrays the loop control variables for ALL BUT THE INNERMOST array
    must be REFERENCES.
    */

    // POINTERS // 
    int ia[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
    int (*p)[4] = ia; // parentheses are essential! -> int *p [4] is an array of 4 pointers to integer not a pointer to an array of 4 integers -or- 
    
    // p is a double pointer because arrays decay into pointers.
    // p now points to the first of the inner arrays which in turn, points to its first element hence:
    std::cout << *p << " -> " << **p << std::endl; // 0xADDRESS (of first array) -> 1
    // accessing inner elements of first inner array
    int *inner_p = *p;
    ++inner_p;  
    std::cout << inner_p << " -> " << *inner_p << std::endl; // 0xADDRESS+sizeof(int) (first array second elem) -> 2

    ++p;
    // p now points to the second of the inner arrays which in turn points to its frist element hence:
    std::cout << *p << " -> " << **p << std::endl; // 0xADDRESS2 (of second array) -> 5
    inner_p = *p; 
    ++inner_p;
    std::cout << inner_p << " -> " << *inner_p << std::endl; // 0xADDRESS2+sizeof(int) (second array second elem) -> 6

    // or with for loop and with iterators!
    for (auto p = std::begin(ia); p != std::end(ia); ++p)
    {
        for (auto q = std::begin(*p); q != std::end(*p); ++q)
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }

    // equivalent to the above...however error prone...
    for (int (*p)[4] = ia; p < ia+3; ++p )
    {
        for (int *q = *p; q < *p+4; ++q )
        {
            std::cout << *q << ' ';
        }
        std::cout << std::endl;
    }

}