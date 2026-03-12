#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 10;
template <class AType>
class arr
{
    AType a[SIZE];

public:
    AType &operator[](int i); // intob[i] instead of intob.get[i]
};

template <class AType1>
AType1 &arr<AType1>::operator[](int i)
{
    if (i < 0 || i > SIZE - 1)
    {
        cout << "Index " << i << " is out-of-bounds.\n";
        exit(1);
    }
    return a[i];
}

int main()
{
    arr<int> intob;
    arr<double> doubleob;
    int i;
    for (i = 0; i < SIZE; i++)
    {
        intob[i] = i;
    }
    for (i = 0; i < SIZE; i++)
    {
        cout << intob[i] << " ";
    }
    cout << endl;

    for (i = 0; i < SIZE; i++)
    {
        doubleob[i] = (double)i / 3;
    }
    for (i = 0; i < SIZE; i++)
    {
        cout << doubleob[i] << " ";
    }
    cout << endl;
    intob[12] = 100; // runtime error (out of bounds)
    return 0;
}