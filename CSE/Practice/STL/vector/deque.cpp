#include <bits/stdc++.h>
using namespace std;
int main()
{
    // can push/pop an element to the front
    // also available size, erase, begin, end, rbegin, rend, insert, front, back
    deque<int> d;
    d.push_back(1);
    d.emplace_back(2);
    d.emplace_front(3);
    d.push_front(4);
    for (auto x : d)
    {
        cout << x << " ";
    }
    cout << endl;
    d.pop_back();
    d.pop_front();
    for (auto x : d)
    {
        cout << x << " ";
    }
    cout << endl;
    // have the access of random memory allocation like d[i]
    cout << d[0] << endl;
    return 0;
}