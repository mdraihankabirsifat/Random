#include <iostream>
using namespace std;

class B
{
public:
    int i;
};

/** * Virtual Inheritance:
 * Using 'virtual' here ensures that any class inheriting from both
 * D1 and D2 will only have ONE instance of class B.
 */
class D1 : virtual public B
{
public:
    int j;
};

class D2 : virtual public B
{
public:
    int k;
};

/** * Multiple Inheritance:
 * D3 inherits from both D1 and D2. Because of virtual inheritance
 * above, there is no ambiguity when accessing member 'i'.
 */
class D3 : public D1, public D2
{
public:
    int product()
    {
        return i * j;
    }
};

int main()
{
    D1 ob1;
    D3 ob3;

    ob1.i = 100;

    // Without 'virtual' in D1 and D2, the compiler wouldn't know
    // if ob3.i refers to the copy from D1 or D2.
    ob3.i = 10;
    ob3.j = 3;

    cout << ob1.i << endl;         // Output: 100
    cout << ob3.i << endl;         // Output: 10
    cout << ob3.product() << endl; // Output: 30

    return 0;
}