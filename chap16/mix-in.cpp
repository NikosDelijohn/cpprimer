#include <iostream>

// https://stackoverflow.com/questions/18773367/what-are-mixins-as-a-concept

// -------------------------------------------------
// Base component
// -------------------------------------------------
struct Number
{
    int value = 0;

    void set(int v) { std::cout << "Base.set\n"; value = v; }
    int  get() const { return value; }
};

// -------------------------------------------------
// Template mixin 1: adds Undo capability
// -------------------------------------------------
// This is a *compile-time* mixin.
// It takes any BASE type that provides get()/set()
// and extends it with state and behavior.
template <typename BASE>
struct Undoable : public BASE
{
    int before = 0;

    void set(int v)
    {
        std::cout << "Undoable.set\n";
        // Save old value before changing it
        before = BASE::get();
        BASE::set(v);
    }

    void undo()
    {
        // Restore previous value
        BASE::set(before);
    }
};

// -------------------------------------------------
// Template mixin 2: adds Redo capability
// -------------------------------------------------
template <typename BASE>
struct Redoable : public BASE
{
    int after = 0;

    void set(int v)
    {
        std::cout << "Redoable.set\n";
        // Save new value after changing it
        after = v;
        BASE::set(v);
    }

    void redo()
    {
        // Re-apply last set value
        BASE::set(after);
    }
};

// -------------------------------------------------
// Compose mixins at compile time
// -------------------------------------------------
// The final type is built by *stacking* mixins.
// Think of it as: Redoable( Undoable( Number ) )
using ReUndoableNumber = Redoable< Undoable< Number > >;

// -------------------------------------------------
// Usage
// -------------------------------------------------
int main()
{
    ReUndoableNumber n;

    n.set(10);   // goes through Redoable::set -> Undoable::set -> Number::set
    n.set(20);

    std::cout << n.get() << "\n";  // 20

    n.undo();    // provided by Undoable
    std::cout << n.get() << "\n";  // 10

    n.redo();    // provided by Redoable
    std::cout << n.get() << "\n";  // 20
}
