#include "ex723.hpp"

Screen::Screen() = default;

Screen::Screen(position height, position width): 
    height(height),
    width(width),
    contents(height*width+height, ' ')
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