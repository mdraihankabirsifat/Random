#include <iostream>
using namespace std;

const int arraySize = 2; // Fixed size for the coordinate array

class Point
{
    int *arr;

public:
    // Constructor initializes a dynamic array of size 2
    Point(int x = 0, int y = 0)
    {
        arr = new int[arraySize];
        arr[0] = x;
        arr[1] = y;
    }

    /**
     * Overloading [] operator
     * Returning int& (reference) allows the subscript to be used on the
     * left-hand side of an assignment (e.g., p1[0] = 6).
     */
    int &operator[](int pos)
    {
        // Bounds checking to prevent illegal memory access
        if (pos < arraySize)
            return arr[pos];
        else
        {
            cout << "Out of bound" << endl;
            exit(0);
        }
    }

    void print()
    {
        cout << "(" << arr[0] << "," << arr[1] << ")" << endl;
    }
};

int main()
{
    Point p1(3, 4);

    p1.print(); // Initial values: (3,4)

    // Using the overloaded [] operator to modify private array elements
    p1[0] = 6;
    p1[1] = 8;

    p1.print(); // Modified values: (6,8)

    return 0;
}