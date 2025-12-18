#include <iostream>
#include <vector>
#include <string>

template <size_t W, size_t H>
class Screen;

template <size_t W, size_t H>
std::istream& operator>>(std::istream&, Screen<W, H>&); 

template <size_t W, size_t H>
class Screen
{
    friend std::istream& operator>><>(std::istream&, Screen&);

    template <size_t X, size_t Y>
    friend std::ostream& operator<<(std::ostream&, const Screen<X, Y>&);

public:

    Screen(): screen(H, std::vector<std::string>(W))
    {}
    ~Screen() = default;

    static constexpr size_t width  = W;
    static constexpr size_t height = H;
private:

    std::vector<std::vector<std::string>> screen;
};

template <size_t W, size_t H>
std::istream& operator>>(std::istream& in, Screen<W, H>& s)
{
    std::string line;
    if (std::getline(in, line))
    {
        if (s.screen.size() == H)
            s.screen.clear();

        if (line.size() <= W)
        {
            s.screen.emplace_back();
            s.screen.back().push_back(line);
        }
        else
        {
            in.setstate(std::ios::failbit);
        }
    }

    return in;
}

template <size_t X, size_t Y>
std::ostream& operator<<(std::ostream& out, const Screen<X, Y>& s)
{
    for (const auto& row: s.screen)
    {
        for (const auto& col: row)
            out << col << " ";
        out << std::endl;
    }

    return out;
}

int main()
{
    Screen<10,3> screen;

    while(std::cin >> screen);

    std::cout <<screen;

    
    return EXIT_SUCCESS;
}