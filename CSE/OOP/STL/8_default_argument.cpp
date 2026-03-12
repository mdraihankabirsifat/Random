#include <iostream>
#include <cstdlib>
using namespace std;
template <class AType = int, int size = 10>
class arr
{
    AType a[size];

public:
    AType &operator[](int i);
};

template <class AType, int size>
AType &arr<AType, size>::operator[](int i)
{
    if (i < 0 || i >= size)
    {
        cout << "Index " << i << " is out-of-bounds.\n";
        exit(1);
    }
    return a[i];
}

int main()
{
    arr<int, 20> intarray;
    arr<double> doublearray;
    arr<> defarray;

    int i;

    cout << "int array: ";
    for (i = 0; i < 20; i++)
        intarray[i] = i;
    for (i = 0; i < 20; i++)
        cout << intarray[i] << " ";
    cout << endl;

    cout << "double array: ";
    for (i = 0; i < 10; i++)
        doublearray[i] = (double)i / 3;
    for (i = 0; i < 10; i++)
        cout << doublearray[i] << " ";
    cout << endl;

    cout << "defarray array: ";
    for (i = 0; i < 10; i++)
        defarray[i] = (double)i / 3; // forced to int
    for (i = 0; i < 10; i++)
        cout << defarray[i] << " ";
    cout << endl;

    return 0;
}