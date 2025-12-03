#include <memory>
#include <stdexcept>

class string
{
    friend bool operator==(const string &, const string &);
    friend bool operator<(const string&, const string &);

public:

    string():
        characters(nullptr),
        first_free(nullptr),
        cap(nullptr)
    {};

    string(const char *);
    string(const string &);
    string(string &&) noexcept;
    ~string();
    
    string& operator=(const string &);
    string& operator=(string &&) noexcept;

    char& operator[](size_t);
    const char& operator[](size_t) const;

    size_t size() const {return first_free - characters;}
    size_t capacity() const { return cap - characters;}
    
    char* begin() const {return characters;}
    char* end() const {return first_free;}

    void resize(size_t, const char & = '\0');
    void reserve(size_t);


    size_t length() {return size();}
    char& back(){return *(first_free - 1);}
    char& front(){return *characters;}
    void clear(){ first_free = characters;}
    const char& at(size_t n)
    {
        if (n < size())
            return *(characters + n);
        else
            throw std::out_of_range("Requested index is out of bounds!");
    };
    void push_back(const char &);
    
    
private:
    static std::allocator<char> alloc;

    std::pair<char *, char *>
    copy_and_allocate(const char *b, const char *e);
    
    void check_and_allocate()
    {
        if (size() == capacity())
            reallocate();
    }

    void free();
    void reallocate();

    char* characters;
    char* first_free; // points to NULL TERMINATOR
    char* cap;
};

