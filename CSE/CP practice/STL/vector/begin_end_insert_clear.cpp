#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "size of the vector: " << v.size() << endl;
    cout << "capacity of the vector: " << v.capacity() << endl;
    v.erase(v.begin() + 2); // erase specific element of the vector
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "size of the vector: " << v.size() << endl;
    cout << "capacity of the vector: " << v.capacity() << endl;
    v.erase(v.begin() + 1, v.begin() + 3); // it removes the elements like [start,end)
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    v.insert(v.begin() + 1, 3); // change the size of the vector
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    v.clear();
    cout << "After clearing: " << endl;
    for (auto x : v)
    {
        cout << x << " ";
    }
    //capacity always remains the same as like before
    cout << "capacity of the Vector: " << v.capacity() << endl;
    return 0;
}