#ifndef _EX723_
#define _EX723_

#include <iostream>
#include <string>

class Screen
{
public:
    using position = std::string::size_type;

    Screen();
    Screen(position, position);
    Screen(position, position, char);
    
    char get() const;
    char get(position, position) const;
    Screen &move(position, position);
    Screen &set(char);
    Screen &display(std::ostream &);

private:
    position cursor = 0u;
    position height = 0u, width = 0u;
    std::string contents;

};

inline
char Screen::get() const 
{ 
    return contents[cursor]; 
}

inline
char Screen::get(position row, position column) const
{
    return contents[row + column];
}

inline
Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

#endif