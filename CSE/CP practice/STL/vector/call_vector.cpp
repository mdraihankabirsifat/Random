#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v = {1, 2}; // hard code every element of the vector
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> v1(3, 7); // automatically declare all the elements to a specific value
    for (auto x : v1)
    {
        cout << x << " ";
    }
    cout << endl;
    vector<int> v2(v1); // store a whole vector into another vector
    for (auto x : v2)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}