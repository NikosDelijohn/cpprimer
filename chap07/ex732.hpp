#ifndef _EX732_
#define _EX732_

#include <iostream>
#include <string>
#include <vector>

// 1. Forward declare 'Screen' for usage within 'Window_mgr' declarations.
class Screen;

class Window_mgr
{
public:
    using screen_index = std::vector<Screen>::size_type;
    
    Window_mgr();
    void clear(screen_index);
private:
    std::vector<Screen> screens;
};

// 2. Fully define 'Screen'
class Screen
{
    friend void Window_mgr::clear(Window_mgr::screen_index);
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

Screen::Screen() = default;

Screen::Screen(position height, position width): 
    height(height),
    width(width),
    contents(height*width, ' ')
    {}

Screen::Screen(position height, position width, char c): 
    height(height),
    width(width),
    contents(height*width, c) // calls constructor of string with those arguments and creates the object in-place. no assignment
    {}

Screen& Screen::move(position row, position column)
{
    position row_on_screen = row * width; // find the row (row 0 position is width*0, 1 is width*1 etc.)
    cursor = row_on_screen + column; // column on the found row.
    return *this;
}

Screen& Screen::display(std::ostream &out)
{
    for (position i = 0; i < height; ++i) {
        out << contents.substr(i * width, width) << '\n';
    }    
    return *this;
}

inline char Screen::get() const 
{ 
    return contents[cursor]; 
}

inline char Screen::get(position row, position column) const
{
    return contents[row*width + column];
}

inline Screen& Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}

// 3. Fully define 'Window_mgr'
Window_mgr::Window_mgr():
    screens({Screen(24, 80)})
{}

inline void Window_mgr::clear(screen_index idx)
{
    Screen &ref = screens[idx];
    ref.contents = std::string(ref.height*ref.width, ' ');
}


#endif