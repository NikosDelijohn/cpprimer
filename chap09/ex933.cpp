#include <iostream>
#include <vector>
using std::vector;

int main() 
{
  vector<int> v = {0,1,2,3,4,5,6,7,8,9};

  auto begin = v.begin();
  
  while (begin != v.end()) 
  {

    ++begin;
    std::cout << *begin << std::endl;

    v.insert(begin, 42); 
    // Insertion happens before the iterator begin.
    // All iterators, references and pointers after
    // the insertion point, become invalid
    // => UB

    std::cout << *begin <<"\n---\n" <<std::endl;
    ++begin;
  }

  return EXIT_SUCCESS;
}