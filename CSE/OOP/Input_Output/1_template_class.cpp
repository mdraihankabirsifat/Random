#include <iostream>
using namespace std;

// 'T' is a placeholder for any data type
template <class T>
class Gen
{
    T val;

public:
    Gen(T v)
    {
        val = v;
    }
    T getval()
    {
        return val;
    }
};

int main()
{
    // You specify the type inside angle brackets < >
    Gen<int> iob(88);
    Gen<double> dob(22.22);
    Gen<char> cob('X');

    cout << "Value: " << iob.getval() << endl; // Output: 88
    cout << "Value: " << dob.getval() << endl; // Output: 22.22
    cout << "Value: " << cob.getval() << endl; // Output: X

    return 0;
}