#include <iostream>
using namespace std;

class Base
{
private:
    int a;

protected:
    int b;

public:
    int c;
    // Constructor
    Base(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    int get()
    {
        return a; // needs getter to access from derived class if private in base
    }
};

class Derived : private Base
{
public:
    Derived(int a, int b, int c) : Base(a, b, c)
    {
    }

    // ❌ Cannot access private member 'a'
    int getA()
    {
        return get();
    } // ERROR

    // ✅ Protected member accessible inside derived
    int getB()
    {
        return b;
    }

    // ✅ Public member becomes private due to private inheritance
    int getC()
    {
        return c;
    }
};

int main()
{
    Derived d(4, 5, 6);

    // ❌ All of these are inaccessible due to private inheritance
    // cout << d.a;  // ERROR
    // cout << d.b;  // ERROR
    // cout << d.c;  // ERROR

    // ✅ Access through public member functions
    cout << "a: " << d.getA() << endl;
    cout << "b: " << d.getB() << endl;
    cout << "c: " << d.getC() << endl;

    return 0;
}