#include <iostream>
#include <cmath>
#include <iomanip> // Often used alongside these for manipulators
using namespace std;

int main()
{
    // 1. width(streamsize w)
    // Sets the minimum field width.
    // IMPORTANT: It only applies to the VERY NEXT output, then resets to 0.
    cout << "Hello" << endl;
    cout.width(10);
    cout << "Hello" << endl; // Right-aligned by default in 10 spaces

    // 2. fill(char ch)
    // Changes the padding character from a space to something else.
    // Unlike width(), this stays active until you change it again.
    cout.width(10);
    cout.fill('*');
    cout << "Hello" << endl; // Output: *****Hello

    // 3. precision(streamsize p)
    // Sets the number of digits displayed. Default is 6.
    cout.precision(8);
    cout << 123.456789 << endl; // Shows 8 digits

    // Practical Table Example from your slide
    cout.fill(' '); // Reset fill to space
    cout.setf(ios::right);
    cout.precision(4);

    for (double x = 2.0; x <= 5; x++)
    {
        cout.width(7);
        cout << x; // First column
        cout.width(12);
        cout << sqrt(x); // Second column
        cout.width(7);
        cout << x * x << endl; // Third column
    }

    return 0;
}