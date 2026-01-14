template <typename T> void f1(T& p)
{
    p = 45;
}

template <typename T> void f2(const T& p)
{
    p = 42;
}

int main()
{
    const int ci = 2;
    int i = 4;

    f1(ci);
    f1(i);
    f2(ci);
    f2(i);
}