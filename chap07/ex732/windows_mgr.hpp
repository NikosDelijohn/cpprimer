#pragma once
#include "screen.hpp"
#include <vector>

class Window_mgr
{
public:
    using screen_index = std::vector<Screen>::size_type;
    
    Window_mgr();
    void clear(screen_index);
private:
    std::vector<Screen> screens;
};

inline
void Window_mgr::clear(screen_index idx)
{
    Screen &ref = screens[idx];
    ref.contents = std::string(ref.height*ref.width, ' ');
}

