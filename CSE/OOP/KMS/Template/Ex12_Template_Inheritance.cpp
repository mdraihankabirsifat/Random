#include <iostream>
using namespace std;

// base template class
template <typename T>
class Box
{
protected:
    T value;
};

// derived class using int specialization
class IntBox : public Box<int>
{
public:
    IntBox(int v)
    {
        value = v;
    }

    int get() const
    {
        return value;
    }
};

int main()
{
    IntBox b(10);
    cout << b.get();
}

/*
Key Notes:

1. Template classes can be inherited.
2. Derived class may specify the template type.
3. Example:
   class IntBox : public Box<int>
*/