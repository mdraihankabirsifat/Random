#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class strtype
{
    char *p;
    int len;

public:
    strtype(char *s);
    ~strtype()
    {
        delete[] p;
    } // Destructor to free dynamic memory
    char *get()
    {
        return p;
    }

    // Assignment operator prototype
    strtype &operator=(strtype &ob);
};

// Constructor: Allocates memory and copies string
strtype::strtype(char *s)
{
    int l;
    l = strlen(s) + 1;
    p = new char[l]; // Dynamic memory allocation
    strcpy(p, s);
    len = l;
}

/** * Overloaded Assignment Operator
 * Prevents "Shallow Copy" (bitwise copy) which would cause
 * two pointers to point to the same memory location.
 */
strtype &strtype::operator=(strtype &ob)
{
    // 1. Allocate new memory for the destination object
    p = new char[ob.len];

    // 2. Copy the actual data (Deep Copy)
    len = ob.len;
    strcpy(p, ob.p);

    // 3. Return the current object to allow chained assignments (e.g., a = b = c)
    return *this;
}

int main()
{
    strtype a("Hello"), b("There");

    // Before assignment
    cout << a.get() << " " << b.get() << endl;

    // Assignment operator called here
    a = b;

    // After assignment
    cout << a.get() << " " << b.get() << endl;

    return 0;
}