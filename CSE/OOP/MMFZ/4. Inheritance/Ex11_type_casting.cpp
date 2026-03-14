#include <iostream>
using namespace std;

class Base
{
public:
    virtual void print()
    {
        cout << "Base" << endl;
    }
};

class Derived : public Base
{
public:
    void print()
    {
        cout << "Derived" << endl;
    }
};

class MyClass
{
};

int main()
{
    // --- Primitive Type Conversions ---
    float length = 4.26;
    // static_cast converts float to int (truncates decimal)
    int num = static_cast<int>(length);
    float wide = num;
    char c = 'A';

    cout << "num: " << num << endl;       // Output: 4
    cout << "length: " << length << endl; // Output: 4.26
    cout << "wide: " << wide << endl;     // Output: 4

    /** * Invalid cast example:
     * int* p = static_cast<int*>(&c); // Error: static_cast cannot cast between unrelated pointer types
     */

    // --- Class Pointer Conversions ---
    Derived *d = new Derived;
    d->print(); // Output: Derived

    // Upcasting: Converting Derived* to Base* (Always safe)
    Base *b = static_cast<Base *>(d);
    b->print(); // Output: Derived (due to virtual function)

    b = new Base();
    b->print(); // Output: Base

    // Downcasting: Converting Base* to Derived* // static_cast does this at compile-time WITHOUT runtime safety checks.
    Base *base = new Base();
    Derived *derived = static_cast<Derived *>(base);
    derived->print(); // Output: Base (Dangerous! Should use dynamic_cast for safety)

    derived = new Derived();
    derived->print(); // Output: Derived

    /**
     * static_cast cannot cast between unrelated classes
     * MyClass* x = static_cast<MyClass*>(d); // Error
     */

    return 0;
}