#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.emplace_back(5);
    v.push_back(3);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    v.pop_back();
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    return 0;
}