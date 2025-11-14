#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

int main()
{

/*
  ____             _      _____                     _            
 |  _ \           | |    |_   _|                   | |           
 | |_) | __ _  ___| | __   | |  _ __  ___  ___ _ __| |_ ___ _ __ 
 |  _ < / _` |/ __| |/ /   | | | '_ \/ __|/ _ \ '__| __/ _ \ '__|
 | |_) | (_| | (__|   <   _| |_| | | \__ \  __/ |  | ||  __/ |   
 |____/ \__,_|\___|_|\_\ |_____|_| |_|___/\___|_|   \__\___|_|   
                                                                 
*/
    std::vector<int> ivec;

    // std::fill_n(ivec.begin(), 10, 0);
    
    // This statement is in error and dangerous.
    // It attempts to write! to an empty container
    // 10 elements to value 0. However, the container
    // is not allocated. Has no elements inside. -> UB

    // ivec.reserve(10);
    // std::fill_n(ivec.begin(), 10, 0);

    // Still NOT ok! Reserve simply allocates capacity
    // Does NOT create these 10 elements however. So still
    // we are writing into an empty vector! -> UB

    ivec.resize(10);
    std::fill_n(ivec.begin(), 10, 0);
    // This is OK! Resize either shrinks or expands
    // the container by creating elements. It does 
    // not just allocate space. Hence the call to fill_n
    // is valid now. We are changing the values of 10 elements
    // to 0.

    // Or alternatively, we can use back inserters, defined 
    // at the iterator header. These iterators can be used to
    // create new elements by invoking the push_back method
    // of the container that they are bound to.
    std::vector<int> ivec2;
    std::back_insert_iterator<std::vector<int>> back_iter = std::back_inserter(ivec2); // or auto back_iter = ...
    std::fill_n(back_iter, 10,0);

    // -> Containers with no push_back cannot use the back_inserter (e.g., forward list)

    std::vector<int> vec3;
    auto iter2 = std::back_inserter(vec3);

    std::copy(ivec2.cbegin(), ivec2.cend(), iter2); 
    //Important Note: Copying without using insert iterators into empty containers
    //is a serious error. -> UB 

    *iter2 = 12345; // pushes back 12345
    std::cout << vec3.at(vec3.size()-1) << std::endl;

    iter2 = 123456; // also the same
    std::cout << vec3.at(vec3.size()-1) << std::endl;


 /*
  ______               _     _____                     _            
 |  ____|             | |   |_   _|                   | |           
 | |__ _ __ ___  _ __ | |_    | |  _ __  ___  ___ _ __| |_ ___ _ __ 
 |  __| '__/ _ \| '_ \| __|   | | | '_ \/ __|/ _ \ '__| __/ _ \ '__|
 | |  | | | (_) | | | | |_   _| |_| | | \__ \  __/ |  | ||  __/ |   
 |_|  |_|  \___/|_| |_|\__| |_____|_| |_|___/\___|_|   \__\___|_|   
                                                                    
                                                                    
*/
    // 2. Front inserter example
    std::list<int> lst;
    std::front_insert_iterator<std::list<int>> front_it = std::front_inserter(lst);
    std::fill_n(front_it, 3, 7); // inserts 7 at front 3 times
    *front_it = 8;               // inserts 8 at front
    front_it = 9;                // inserts 9 at front

    std::cout << "List contents (front_inserter): ";
    for (int x : lst) std::cout << x << " ";
    std::cout << "\n";


/*
  _____                     _            
 |_   _|                   | |           
   | |  _ __  ___  ___ _ __| |_ ___ _ __ 
   | | | '_ \/ __|/ _ \ '__| __/ _ \ '__|
  _| |_| | | \__ \  __/ |  | ||  __/ |   
 |_____|_| |_|___/\___|_|   \__\___|_|   
                                         
                                         
*/
    // 3. General inserter example (insert at specific position)
    std::vector<int> vec2{1, 2, 3, 5, 6, 7, 8, 9, 10};
    auto it = vec2.begin() + vec2.size()/2; // position at idx 4
    std::insert_iterator<std::vector<int>> ins_it = std::inserter(vec2, it);
    std::fill_n(ins_it, 2, 99); // inserts 99 twice starting at position 4!
    
    //*ins_it = 77; // Error. The ins_it has been updated at fill_n and it doesn't point to the updated
    // location after the insertion of the two 99 elements. Hence this pre-existing iterator is invalid now
    ins_it = std::inserter(vec2, vec2.begin() + vec2.size()/2);
    *ins_it = 77;  // now safe

    std::cout << "Vector contents (inserter at position 1): ";
    for (int x : vec2) std::cout << x << " ";
    std::cout << "\n";


    return EXIT_SUCCESS;
}