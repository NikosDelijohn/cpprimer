#include <iostream>
#include <vector>
/*
Fast Random Access
Fast Insertion/Deletion at the back
*/
#include <deque>
/* Double ended queue
Fast Random Access
Fast Insertion/Deletion at the front and the back
*/
#include <list>
/* Doubly Linked List
Bidirectional Sequential Access
Fast Insertion/Deletion at any point in the list.
*/
#include <forward_list>
/* Singly Linked List
One Direction Sequential Access
Fast Insertion/Deletion at any point in the list.
*/
#include <array>
/* Fixed-size array
Supports Random Access
No Insertion/Deletion of elements
*/
#include <string>
/*
Fast Random Access
Fast Insertion/Deletion at the back
*/
#include "../help.hpp"

int main()
{
    std::vector<int> vec_int = {1,2,3,4,5,6};
    std::deque<int> deq_int = {1,2,3,4,5,6};
    std::list<int> list_int = {1,2,3,4,5,6};
    std::forward_list<int> fwlist_int = {1,2,3,4,5,6};
    std::array<int, 6> arr_int = {1,2,3,4,5,6};

/*
  _____ _                 _                 
 |_   _| |               | |                
   | | | |_ ___ _ __ __ _| |_ ___  _ __ ___ 
   | | | __/ _ \ '__/ _` | __/ _ \| '__/ __|
  _| |_| ||  __/ | | (_| | || (_) | |  \__ \
 |_____|\__\___|_|  \__,_|\__\___/|_|  |___/                                       
*/

    std::vector<int>::iterator beg = vec_int.begin();
    std::vector<int>::iterator end = vec_int.end();
    std::vector<int>::const_iterator cbeg = vec_int.cbegin();
    std::vector<int>::const_iterator cend = vec_int.cend();
    std::vector<int>::reverse_iterator rbeg = vec_int.rbegin(); // points to last
    std::cout << (*rbeg == *--end) << std::endl; // expect 1
    std::vector<int>::reverse_iterator rend = vec_int.rend(); // points to one before first
    std::cout << (*--rend == *beg) << std::endl; // expect 1
    std::vector<int>::const_reverse_iterator crbeg = vec_int.crbegin();
    std::vector<int>::const_reverse_iterator crend = vec_int.crend();
    // Same for all except: forward_list and list (not all are supported)

    // Exceptions to iterator arithmetic: forward_list and list
    std::forward_list<int>::iterator fwlend = fwlist_int.end(); //ok
    std::forward_list<int>::iterator fwlbeg = fwlist_int.begin();
    
    std::list<int>::iterator lbeg = list_int.begin();
    std::list<int>::iterator lend = list_int.end();
    std::list<int>::reverse_iterator rlbeg = list_int.rbegin(); // ok! bi-directional
    //std::forward_list<int>::reverse_iterator rbeg; // nope! one-directional!

    // --fwlend; // also not ok. one-directional!
    ++fwlbeg; // ok!
    
    --lend; // ok!
    ++lbeg; // ok!
    
    // lbeg + 1; // not ok
    // fwlbeg + 1; // not ok

    //lend - lbeg; // not ok!
    //flwend - flwbeg; // not ok!

    while(lbeg != lend) // ok ! < or > not ok!
    {
        break;
    }

    // Performance test
    std::vector<int> vec = {1,2};
    std::deque<int> deq = {1,2};

    auto start = tic();
    vec.insert(vec.begin(), 4);
    auto stop = tac(start);
    std::cout << "Insertion at the front of vector took " << stop << " ms\n";

    start = tic();
    deq.push_front(4);
    stop = tac(start);
    std::cout << "Insertion at the front of deque  took " << stop << " ms\n";

    const std::vector<int> vec0 = {1,2};

    return EXIT_SUCCESS;
}