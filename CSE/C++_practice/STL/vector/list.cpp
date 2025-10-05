#include <bits/stdc++.h>
using namespace std;
int main()
{
    // can push/pop an element to the front
    // also available size, erase, begin, end, rbegin, rend, insert, front, back
    list<int> l;
    l.push_back(1);
    l.emplace_back(2);
    l.emplace_front(3);
    l.push_front(4);
    for (auto x : l)
    {
        cout << x << " ";
    }
    cout << endl;
    l.pop_back();
    l.pop_front();
    for (auto x : l)
    {
        cout << x << " ";
    }
    cout << endl;
    //can not access random memory allocation like l[i]
    return 0;
}