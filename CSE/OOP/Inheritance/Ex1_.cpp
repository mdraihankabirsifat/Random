#include <iostream>
using namespace std;

// Base class definition
class base
{
    int x, y;

public:
    // Base constructor
    base(int n, int p)
    {
        x = n;
        y = p;
        cout << "Constructing base class\n";
    }
    // Base destructor
    ~base()
    {
        cout << "Destructing base class\n";
    }
    void showxy()
    {
        cout << x << " " << y << "\n";
    }
};

// Derived class inherits from base
class derived : public base
{
    int i, j;

public:
    /**
     * Derived Constructor:
     * It must pass required arguments to the base class constructor
     * using the initialization list syntax ': base(n, p)'.
     */
    derived(int n, int m, int p) : base(n, p)
    {
        i = n;
        j = m;
        cout << "Constructing derived class\n";
    }
    // Derived destructor
    ~derived()
    {
        cout << "Destructing derived class\n";
    }
    void showij()
    {
        cout << i << " " << j << "\n";
    }
};

int main()
{
    // Object creation triggers constructors: Base first, then Derived
    derived ob(10, 20, 30);

    ob.showxy(); // Accessing base class method
    ob.showij(); // Accessing derived class method

    return 0;
    // Program end triggers destructors: Derived first, then Base
}