#include <iostream>
#include <cstring>
using namespace std;

class Rectangle
{
    char name[20];
    int length;
    int wide;

public:
    // Constructor uses 'this->' to resolve name conflicts between members and parameters
    Rectangle(char *name, int length, int wide)
    {
        strcpy(this->name, name);
        this->length = length;
        this->wide = wide;
    }

    /**
     * Conversion function: Object to double
     * Format: operator type() { return value; }
     * Note: No return type is specified before 'operator'.
     */
    operator double()
    {
        return length * wide; // Returns the area
    }

    /**
     * Conversion function: Object to char*
     * Logic: Allows the object to be assigned directly to a string/char pointer.
     */
    operator char *()
    {
        return name;
    }
};

int main()
{
    Rectangle r("Rectangle", 5, 10);

    // unBoxing: Assigning the object 'r' to a double triggers 'operator double()'
    double area = r;
    cout << "Area: " << area << endl;

    // unBoxing: Assigning the object 'r' to a char* triggers 'operator char*()'
    char *name = r;
    cout << "Name: " << name << endl;

    return 0;
}