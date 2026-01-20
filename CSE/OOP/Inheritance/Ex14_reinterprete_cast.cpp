#include <iostream>
using namespace std;

struct mystruct
{
    int a = 5;
    char c = 'a';
};

class A
{
public:
    void display()
    {
        cout << "Class A" << endl;
    }
};

class B
{
public:
    void display()
    {
        cout << "Class B" << endl;
    }
};

int main()
{
    // Casting int pointer to char pointer
    int *p = new int(65);
    char *ch = reinterpret_cast<char *>(p);

    cout << *p << endl;  // Output: 65
    cout << *ch << endl; // Output: A (ASCII 65)
    cout << p << endl;   // Output: Memory address

    // Casting struct pointer to int pointer to traverse memory
    mystruct s;
    int *iptr = reinterpret_cast<int *>(&s);
    cout << *iptr << endl; // Output: 5
    iptr++;                // Move to next memory block (where 'c' is stored)
    cout << *iptr << endl; // Output: 32609 (garbage/unaligned char data)

    // Casting between unrelated classes
    B *b = new B();
    b->display(); // Output: Class B
    A *a = reinterpret_cast<A *>(b);
    a->display(); // Output: Class A

    return 0;
}