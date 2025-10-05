#include <bits/stdc++.h>
using namespace std;
int main()
{
    //indexing not allowed
    set<int> s;
    s.insert(3);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << *s.rbegin() << "\n"; // max

    set<int, greater<int>> t;
    t.insert(3);
    t.insert(5);
    t.insert(1);
    t.insert(2);
    for (auto x : t)
    {
        cout << x << " ";
    }
    cout << "\n";
    cout << *t.begin() << "\n"; // begin
    t.erase(5);
    for (auto x : t)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}