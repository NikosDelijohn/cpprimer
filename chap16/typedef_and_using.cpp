// Demonstrates typedef vs using with templates and dependent types

/*

Inside a template, you must write typename only when all three are true:

   1. The name is qualified (uses ::)
   2. The name is dependent on a template parameter
   3. The name refers to a type
*/

#include <vector>
#include <iostream>

// -------------------------------
// Example 1: Class template using typedef
// -------------------------------
template <typename T>
class BoxTypedef
{
public:
    // T is known to be a type → no 'typename'
    typedef T value_type;

    // Dependent qualified type → requires 'typename'
    typedef typename std::vector<T>::size_type size_type;

    BoxTypedef() : data{} {}

    size_type size() const {
        return data.size();
    }

    void push(const value_type& v) {
        data.push_back(v);
    }

private:
    std::vector<T> data;
};

// -------------------------------
// Example 2: Class template using 'using'
// -------------------------------
template <typename T>
class BoxUsing
{
public:
    // Same rules apply with 'using'
    using value_type = T;

    // 'typename' still required
    using size_type = typename std::vector<T>::size_type;

    BoxUsing() : data{} {}

    size_type size() const {
        return data.size();
    }

    void push(const value_type& v) {
        data.push_back(v);
    }

private:
    std::vector<T> data;
};

// -------------------------------
// Example 3: Function template using dependent type
// -------------------------------
template <typename Container>
void print_size(const Container& c)
{
    // Dependent qualified name → 'typename' required
    typename Container::size_type sz = c.size();
    std::cout << "size = " << sz << '\n';
}

// -------------------------------
// main
// -------------------------------
int main()
{
    BoxTypedef<int> a;
    a.push(1);
    a.push(2);

    BoxUsing<int> b;
    b.push(10);
    b.push(20);
    b.push(30);

    print_size(a);
    print_size(b);

    return 0;
}
