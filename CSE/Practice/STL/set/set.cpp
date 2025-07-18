#include <bits/stdc++.h>
using namespace std;
int main()
{
    // sorted order, no repeatation
    // insert, emplace, count, erase, find, size, empty, erase
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(5);
    s.insert(1);
    cout << s.size() << endl;
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
    cout << "Lower bound for 3: " << *(s.lower_bound(3)) << endl; // not less than key; equal or greater then key
    cout << "Upper bound for 3: " << *(s.upper_bound(3)) << endl; // greater than key
    cout << "Lower bound for 4: " << *(s.lower_bound(4)) << endl;
    cout << "Lower bound for 5: " << *(s.lower_bound(6)) << endl; // if not found in set, garbage value

    return 0;
}