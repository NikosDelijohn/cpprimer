#include <iostream>
// Adaptors for Sequential containers are:
// 1. Stack
// 2. Queue
// 3. Priority Queue (also defined in queue header)
#include <stack>
#include <queue>
// They are built upon Sequential containers:
#include <vector>
#include <string>
#include <deque>
#include <list>
#include <forward_list>
#include <array>

int main()
{
    // All adaptors require the ability to add/remove elements!
    // Hence, they cannot be built upon an array
    // Hence, the cannot be built upon a forward_list
    //        because a forward_list allows adding only
    //        at the front

    /*
        === Defaults ===
        The stack and queue adaptors are by default built on deque
        The priority_queue adaptor is by default built on vector

        === Definition & Initialization ===
    */
    std::stack<int> stack; // Emtpy adaptor, which holds a deque, that has integers
    // We can override the default constructor and define a different, valid
    // sequential container as an underlying type. However, the container type
    // must be a match with the adaptor. So
    std::stack<int, std::list<int>> stack_list_of_ints;
    // Is valid. We make a list of ints behave as a stack. Note the matching int types
    // on the template. However, this is also "allowed" at my compiler 
    std::stack<int, std::list<std::string>> stack_in_error;
    // This will compile, the underlying type, which is what actually stores the data
    // is allowing strings but the stack is defined as an int-holding type.
    
    // stack_in_error.push(42); // not compiling 
    stack_in_error.push("42"); // compiling.
    // However, the above is nonsensical...

    // === Allowed Containers per Adaptor ===
    
    // A stack requires only a push_back, a pop_back and back operations. Hence, all of 
    // the remaining valid containers (excluding those in lines 19, 20) are valid for 
    // a stack. 

    // A queue requires a back, push_back, front and push_front so it can be built on a
    // list and a deque but NOT on a vector

    // A priority queue requires random access in addition to front, push_back, and pop_back.
    // So it can be built on a vector and a deque but NOT on a list

/*
   _____ _             _    
  / ____| |           | |   
 | (___ | |_ __ _  ___| | __
  \___ \| __/ _` |/ __| |/ /
  ____) | || (_| | (__|   < 
 |_____/ \__\__,_|\___|_|\_\

 Good ol LIFO
*/  
    struct dummy
    {
        int x, y;
        dummy(int xx, int yy) { x = xx; y = yy;}
    };

    std::stack<int> int_stack;

    // Pushing - Filling the stack
    for (size_t idx = 0; idx != 10; ++idx)
        int_stack.push(idx); 
    
    // Popping - Emptying the stack
    while (!int_stack.empty())
    {
        int topmost = int_stack.top();
        std::cout << "Topmost stack element: " << topmost << std::endl;
        int_stack.pop();
    }
    

    std::vector<dummy> vec = { {1,2}, {3,4}, {4,5}, {6,7} };
    //std::stack<dummy> another_stack(vec); // not possible, because its built on deque by default
    std::stack<dummy, std::vector<dummy>> another_stack(vec); // possible, explicitly specifying a vector as a container
    another_stack.emplace(65,65); // calls constructor with args

    std::cout << another_stack.top().x << ' ' << another_stack.top().y << std::endl;

/*
   ____                        
  / __ \                       
 | |  | |_   _  ___ _   _  ___ 
 | |  | | | | |/ _ \ | | |/ _ \
 | |__| | |_| |  __/ |_| |  __/
  \___\_\\__,_|\___|\__,_|\___|

  Good ol FIFO
*/  
    std::queue<int> queue;

    for(size_t idx = 0; idx != 10; ++idx)
        queue.push(idx);
    
    while(!queue.empty())
    {
        auto front = queue.front();
        std::cout << "Front queue element: " << front << std::endl;
        queue.pop();
    }
    std::cout << "\n";

/*
  _____      _            _ _            ____                        
 |  __ \    (_)          (_) |          / __ \                       
 | |__) | __ _  ___  _ __ _| |_ _   _  | |  | |_   _  ___ _   _  ___ 
 |  ___/ '__| |/ _ \| '__| | __| | | | | |  | | | | |/ _ \ | | |/ _ \
 | |   | |  | | (_) | |  | | |_| |_| | | |__| | |_| |  __/ |_| |  __/
 |_|   |_|  |_|\___/|_|  |_|\__|\__, |  \___\_\\__,_|\___|\__,_|\___|
                                 __/ |                               
                                |___/
*/

    // Assigns priorities within the elements it holds. There is no 
    // front element or back element. There is just the TOP element
    // the one with the highest priority. By default the priority 
    // is assigned according to the less than ( < ) operator among
    // the elements it holds.

    // Hence, if for a class type, then the class should have an 
    // appropriate < overload or the priority criterion should change!

    std::priority_queue<int> prio_queue;
    for(size_t idx = 0; idx != 10; ++idx)
        prio_queue.push(idx);
    
    // highest priority element should be 9, then 8, then 7 etc.
    
    while(!prio_queue.empty())
    {
        auto front = prio_queue.top();
        std::cout << "Front queue element: " << front << std::endl;
        prio_queue.pop();
    }

    return EXIT_SUCCESS;
}
