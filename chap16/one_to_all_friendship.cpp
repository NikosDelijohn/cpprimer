#include <iostream>

// Forward declaration of the *friend* template.
// We must tell the compiler that Inspector is a template,
// but we do NOT bind it to any specific type yet.
template <typename U>
class Inspector;


// ==========================
// "ONE" template class
// ==========================
template <typename T>
class Secret
{
private:
    T value;

    /*
        Why this exact syntax?

        template <typename U>
        friend class Inspector;

        1) "friend class Inspector;" alone is INVALID
           because Inspector is a class template.

        2) "friend class Inspector<T>;" would mean:
           "Only Inspector<T> is my friend"
           → this would be ONE-to-ONE (T ↔ T).

        3) "template <typename U> friend class Inspector;"
           introduces a *new template parameter U* that is
           INDEPENDENT of T.

           Meaning:
           For this Secret<T>,
           EVERY Inspector<U> is a friend.

        This is what creates ONE → MANY friendship.
    */
    template <typename U>
    friend class Inspector;

public:
    explicit Secret(T v) : value(v) {}
};


// ==========================
// "MANY" template class
// ==========================
template <typename U>
class Inspector
{
public:
    /*
        This function itself is templated on T.

        Why?
        Because Inspector<U> must be able to inspect
        Secret<T> for ANY T.

        If we wrote:
            void inspect(const Secret<U>&);

        then Inspector<char> could only inspect Secret<char>,
        which is NOT one-to-many.
    */
    template <typename T>
    void inspect(const Secret<T>& s) const
    {
        // This access is legal because Secret<T> declared
        // *all* Inspector<U> as friends.
        std::cout << "Inspector sees: " << s.value << "\n";
    }
};


int main()
{
    Secret<int>    si{42};
    Secret<double> sd{3.14};

    Inspector<char>   ic;
    Inspector<long>   il;
    Inspector<double> id;

    // All combinations are valid:
    ic.inspect(si);   // Inspector<char> → Secret<int>
    il.inspect(sd);   // Inspector<long> → Secret<double>
    id.inspect(si);   // Inspector<double> → Secret<int>
}
