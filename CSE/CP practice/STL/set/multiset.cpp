#include <bits/stdc++.h>
using namespace std;
int main()
{
    // store repeated values in ascending order
    multiset<int> s;
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.insert(4);
    s.insert(3);
    for (auto x : s)
    {
        cout << x << " ";
    }
    return 0;
}