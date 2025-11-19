#include <iostream>
#include <memory>
#include <vector>
#include <string>

class String_Blob
{
public:
    using size_type = std::vector<std::string>::size_type;

    String_Blob();
    String_Blob(std::initializer_list<std::string>);

    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;

    void push_back(const std::string &);
    void pop_back();

    long get_uses() { return data.use_count(); }

private:
    void check(size_type, const std::string &) const;
    std::shared_ptr<std::vector<std::string>> data;

};

String_Blob::String_Blob(): 
    data(std::make_shared<std::vector<std::string>>())
{}

String_Blob::String_Blob(std::initializer_list<std::string> strings):
    data(std::make_shared<std::vector<std::string>>(strings))
{}

inline
void String_Blob::check(size_type idx, const std::string &str) const
{
    if(idx >= data->size())
    {
        throw std::out_of_range(str);
    }
}

inline
const std::string& String_Blob::front() const
{
    check(0, "There is no front element");
    return data->front();
} 

inline
const std::string& String_Blob::back() const
{
    check(data->size() - 1, "There is no back element");
    return data->back();
}

inline
std::string& String_Blob::front()
{
    check(0, "There is no front element");
    return  data->front();
}

inline
std::string& String_Blob::back()
{
    check(data->size() - 1, "There is no back element");
    return data->back();
}

void String_Blob::pop_back()
{
    check(data->size() - 1, "Nothing to pop!");
    data->pop_back();
}

int main()
{
    String_Blob B1 = {"This", "is", "a", "blob!"};
    {
        String_Blob B2 = B1; // default copy constructor used.
        const String_Blob B3 = B2; // B3 itself cannot modify its members. however, due to shared_ptr, others can! Shared ownership doesn't guarantee constness

        std::cout << B3.back() << std::endl;
        B2.pop_back();
        std::cout << B3.back() << std::endl;

        std::cout << "Shared vector has " << B1.get_uses() << " managers" << std::endl;
    }
    
    std::cout << "Shared vector has " << B1.get_uses() << " managers." << std::endl;

    return EXIT_SUCCESS;
}