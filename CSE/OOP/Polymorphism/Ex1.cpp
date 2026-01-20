#include <iostream>
using namespace std;

class Coord
{
    int x, y;

public:
    // Constructor with default arguments
    Coord(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }

    // Member function to get values
    void getxy(int &i, int &j)
    {
        i = x;
        j = y;
    }

    // Binary Operator: Object + Object
    Coord operator+(Coord ob)
    {
        Coord temp;
        temp.x = x + ob.x; // 'x' is implicit (*this), 'ob.x' is explicit
        temp.y = y + ob.y;
        return temp;
    }

    // Binary Operator: Object + int
    Coord operator+(int i)
    {
        Coord temp;
        temp.x = x + i;
        temp.y = y + i;
        return temp;
    }

    // Unary Operator: Prefix Increment (++ob)
    Coord operator++()
    {
        ++x; // Changes the object directly
        ++y;
        return *this; // Returns the updated object implicitly
    }

    // Unary Operator: Postfix Increment (ob++)
    // The 'int' parameter is a dummy to distinguish from prefix
    Coord operator++(int notused)
    {
        Coord temp = *this; // Save original state
        x++;                // Increment current object
        y++;
        return temp; // Return the old state
    }

    // Unary Operator: Negation (-ob) where object is NOT changed
    Coord operator-()
    {
        Coord temp;
        temp.x = -x;
        temp.y = -y;
        return temp; // Returns new object, original remains unchanged
    }

    // Friend function for: int + Object
    friend Coord operator+(int i, Coord ob) // friend function can access the private members
    {
        Coord temp;
        temp.x = i + ob.x;
        temp.y = i + ob.y;
        return temp;
    }

    void display()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    Coord c1(10, 10), c2(5, 5), c3;

    // Binary +
    c3 = c1 + c2;
    cout << "c1 + c2: ";
    c3.display();

    // Prefix ++
    ++c1;
    cout << "After ++c1: ";
    c1.display();

    // Postfix ++
    c3 = c2++;
    cout << "c3 (assigned c2++): ";
    c3.display(); // Old value
    cout << "c2 (after c2++): ";
    c2.display(); // New value

    // Unary -
    c3 = -c1;
    cout << "Unary -c1: ";
    c3.display();

    return 0;
}