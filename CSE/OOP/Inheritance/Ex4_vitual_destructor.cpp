#include <iostream>
using namespace std;

// --- Abstract Base Class ---
class area
{
protected:
    double dim1, dim2;

public:
    void setarea(double d1, double d2)
    {
        dim1 = d1;
        dim2 = d2;
    }

    void getdim(double &d1, double &d2)
    {
        d1 = dim1;
        d2 = dim2;
    }

    /** * Pure Virtual Function:
     * It has no definition in the base class (set to = 0).
     * Any derived class MUST implement this function to be instantiable.
     */
    virtual double getarea() = 0;
};

// --- Derived Class 1 ---
class rectangle : public area
{
public:
    // Implementation of the pure virtual function
    double getarea()
    {
        double d1, d2;
        getdim(d1, d2);
        return d1 * d2;
    }
};

// --- Derived Class 2 ---
class triangle : public area
{
public:
    // Implementation of the pure virtual function
    double getarea()
    {
        double d1, d2;
        getdim(d1, d2);
        return 0.5 * d1 * d2;
    }
};

int main()
{
    /** * area p; -> NOT PERMITTED because 'area' is an abstract class.
     * However, you CAN create a pointer to an abstract class.
     */
    area *p;
    rectangle r;
    triangle t;

    r.setarea(3.3, 4.5);
    t.setarea(4.0, 5.0);

    // Using base pointer for polymorphism
    p = &r;
    cout << p->getarea() << '\n'; // Output: 14.85

    p = &t;
    cout << p->getarea() << '\n'; // Output: 10

    return 0;
}