#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "../help.hpp"

struct custom_type
{
    int x;

    // This won't work. The istream_iterator expects a free (non-member function!)
    std::istream& operator>>(std::istream &is)
    {
        return is >> x;
    }
};

// This will work! This is the version that the iterator expects
std::istream& operator>>(std::istream &is, custom_type &ct)
{
    return is >> ct.x;
}

// This is just an overload to use std::cout << ct rather than << ct.x
std::ostream& operator<<(std::ostream &os, custom_type &ct)
{
    return os << ct.x;
}

int main()
{

/*
  _____     _                            
 |_   _|   | |                           
   | |  ___| |_ _ __ ___  __ _ _ __ ___  
   | | / __| __| '__/ _ \/ _` | '_ ` _ \ 
  _| |_\__ \ |_| | |  __/ (_| | | | | | |
 |_____|___/\__|_|  \___|\__,_|_| |_| |_|
             
*/

    /* Streams are not containers. However, we can use iterators to treat them as such and use
    algorithms on them.
    
    An istream_iterator reads an input stream and an ostream_iterator writes an output stream
    They treat their corresponding stream as a sequence of elements of a specified type*/

    std::istream_iterator<int> int_iter(std::cin); // reads ints from std::cin
    std::istream_iterator<int> eof; // we use an empty iter as an EOF

    while(int_iter != eof)
    {   
        if (*int_iter == -1) break;
        std::cout << *int_iter++ << std::ends;
    }
    std::cout << std::endl;
    
    // IMPORTANT //
    // the iterator<T> type T must have the appropriate operator overload 
    // defined in order for the stream iterator to work. For example
    struct test
    {
        int x;
    };
    // We cannot have an istream iterator for this type because we haven't yet
    // overloaded the >> operator required. The type test must have a way to be 
    // read from a stream

    //std::istream_iterator<test> test_iter(std::cin); // error!
    /*
/usr/include/c++/10/bits/stream_iterator.h:137:39: error: no match for ‘operator>>’ 
(operand types are ‘std::istream_iterator<main()::test>::istream_type’ {aka ‘std::basic_istream<char>’} and ‘main()::test’)
    */

    // Now with the custom_type struct
    std::istream_iterator<custom_type> test_iter2(std::cin);
    std::istream_iterator<custom_type> ct_eof;
    std::vector<custom_type> ct_vec;
    while(test_iter2 != ct_eof && (*test_iter2).x != -1)
        ct_vec.push_back(*test_iter2++);
    
    for (auto &elem: ct_vec)
    {
        std::cout << elem << " "<< std::ends;
    }

    std::cout << std::endl;

/*
   ____      _                            
  / __ \    | |                           
 | |  | |___| |_ _ __ ___  __ _ _ __ ___  
 | |  | / __| __| '__/ _ \/ _` | '_ ` _ \ 
 | |__| \__ \ |_| | |  __/ (_| | | | | | |
  \____/|___/\__|_|  \___|\__,_|_| |_| |_|
                                          
                                          
*/
    std::ofstream file("stream_iterators");
    std::ostream_iterator<int> of_iter(file, " "); // second argument is delimiter
    std::vector<int> integers = {1,2,3,4,5,6};

    // write vector to file
    for(auto it = integers.begin(); it != integers.end(); ++it)
        *of_iter = *it;  // push value to stream
    
    // or (write it again)
    std::copy(integers.begin(), integers.end(), of_iter);
    file.close();

    // what is more usefull is that we can embed these iterators 
    // to functions that require iter range.
    // Like for instance, vector direct initialization with begin and end
    std::ifstream file2("stream_iterators");

    std::istream_iterator<int> if_iter(file2);
    std::istream_iterator<int> if_eof;
    std::vector<int> integers2(if_iter, if_eof); // this!

    for (auto &elem: integers2) std::cout << elem << " " << std::ends; std::cout << std::endl;
    return EXIT_SUCCESS;

}