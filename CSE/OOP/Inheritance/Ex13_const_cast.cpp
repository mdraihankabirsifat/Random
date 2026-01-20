#include <iostream>
using namespace std;

int funct(int *ptr)
{
    *ptr = *ptr + 10;
    return *ptr;
}

class Student
{
    int roll;

public:
    Student(int r)
    {
        roll = r;
    }

    // Modifying a member variable inside a 'const' function
    void funct() const
    {
        (const_cast<Student *>(this))->roll = 5;
    }
    int getRoll() const 
    { return roll; }
};

int main()
{
    const int num = 10;
    const int *ptr1 = &num;

    // Removing constness to pass to a function expecting int*
    int *ptr2 = const_cast<int *>(ptr1);
    cout << "Value after funct: " << funct(ptr2) << endl;

    Student std(3);
    cout << "Roll before: " << std.getRoll() << endl;
    std.funct(); // Internally uses const_cast to change roll to 5
    cout << "Roll after: " << std.getRoll() << endl;

    return 0;
}