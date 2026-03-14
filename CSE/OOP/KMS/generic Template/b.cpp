#include <iostream>
using namespace std;

// Generic template
template <class X>
void swapargs(X &a, X &b)
{
    X temp;
    temp = a;
    a = b;
    b = temp;
    cout << "Inside template swapargs.\n";
}

// Template specialization for int
template <>
void swapargs<int>(int &a, int &b)
{
    cout << "Inside swapargs int specialization.";
    cout << "sum: " << a + b << "\n";
}

void swapargs(int &a, int &b) // priority 1
{
    cout << "Inside swapargs int specialization.";
    cout << "new: " << a - b << "\n";
}

int main()
{
    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'x', b = 'z';

    cout << "Original i, j: " << i << " " << j << "\n";
    cout << "Original x, y: " << x << " " << y << "\n";
    cout << "Original a, b: " << a << " " << b << "\n";

    swapargs(i, j);
    swapargs(x, y);
    swapargs(a, b);

    cout << "Swapped i, j: " << i << " " << j << "\n";
    cout << "Swapped x, y: " << x << " " << y << "\n";
    cout << "Swapped a, b: " << a << " " << b << "\n";

    return 0;
}
/*A generic function cannot change its behavior depending on the type.
It must use the same algorithm, only the data type changes*/