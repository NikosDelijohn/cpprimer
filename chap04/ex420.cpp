#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vals{1,2,3,4,5};
    std::vector<int>::iterator iter = vals.begin();

    std::cout << *iter++ << std::endl; // ok it prints current value and increments the iter. now points to 2 (++ has higher precedence than *)
    std::cout << (*iter)++ << std::endl;; // ok, the second value in which iter currently points (2) is incremented by 1 after it gets printed out.
    std::cout << vals[1] << std::endl; // should be 3 now.
    //std::cout << *iter.empty() << std::endl; // wrong statement. dot oper has > precedence than *. thus, we try to access empty() of iterator type which doesn't exist and then dereference it
    //std::cout << iter->empty() << std::endl; // this is wrong, albeit the -> is correct there is no empty() member for integers. 
    std::cout << ++*iter << std::endl; // Although ++ has higher precedence than *, * binds first to the iter. Hence what will happen here is that 
    // first we will dereference iter and then increment that value by one. The iter points to val[1] still which was 3. Expect 4 now.
    //std::cout << iter++->empty() << std::endl; // wrong statement. -> has higher precedence. tries to access member empty() from iterators. 
    return 0;
}