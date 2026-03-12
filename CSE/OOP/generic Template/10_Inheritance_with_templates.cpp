#include <iostream>
using namespace std;

template <typename T>
class Box
{
protected:
    T value;

public:
    Box(T v)
    {
        value = v;
    }
    T get() const
    {
        return value;
    }
};

// specialization for int
template <>
class Box<int>
{
protected:
    int value;

public:
    Box(int v)
    {
        value = v;
    }
    int get() const
    {
        return value;
    }
};
template <typename T>
class IntBox : public Box<T>
{
public:
    IntBox(T v) : Box<T>(v)
    {
    }
};

int main()
{
    IntBox b(10.1);
    cout << b.get();
    return 0;
}