#include <iostream>
#include <cstdlib>
using namespace std;

class Myclass
{
    int a;

public:
    /**
     * 'explicit' prevents the compiler from using this constructor
     * for implicit conversions (like 'Myclass ob = 20;').
     */
    explicit Myclass(int x)
    {
        a = x;
    }

    /**
     * This constructor is NOT explicit, so it supports "Auto-Boxing"
     * where a char* can be automatically converted to a Myclass object.
     */
    Myclass(char *str)
    {
        a = atoi(str);
    }

    int getA()
    {
        return a;
    }
};

int main()
{
    // 1. Direct Initialization: Works for both explicit and non-explicit
    Myclass ob1(10);

    // 2. Implicit Conversion: Fails because the int constructor is 'explicit'
    // Myclass ob2 = 20; // ERROR

    // 3. Direct Initialization with string
    Myclass ob3("40");

    // 4. Implicit Conversion (Auto-Boxing): Works because char* constructor is not explicit
    Myclass ob4 = "60";

    cout << "ob1: " << ob1.getA() << endl;
    cout << "ob3: " << ob3.getA() << endl;
    cout << "ob4: " << ob4.getA() << endl;

    return 0;
}