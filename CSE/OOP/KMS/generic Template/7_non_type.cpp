#include <iostream>
#include <cstdlib>
using namespace std;

template <class AType, int size>
class arr
{
    AType a[size];

public:
    arr()
    {
        for (int i = 0; i < size; i++)
        {
            a[i] = i;
        }
    }
    AType &operator[](int i)
    {
        if (i < 0 || i >= size)
        {
            cout << "Index " << i << " is out-of-bounds\n";
            exit(1);
        }
        return a[i];
    }
    //AType &operator[](int i);
};

//template <class AType, int size>
// AType &arr<AType, size>::operator[](int i)
// {
//     if (i < 0 || i >= size)
//     {
//         cout << "Index " << i << " is out-of-bounds\n";
//         exit(1);
//     }
//     return a[i];
// }

int main()
{
    arr<int, 10> intob;
    arr<double, 15> doubleob;

    for (int i = 0; i < 10; i++)
    {
        cout << intob[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 15; i++)
    {
        cout << doubleob[i] << " ";
    }
    cout << endl;

    intob[12] = 100; // runtime error
}