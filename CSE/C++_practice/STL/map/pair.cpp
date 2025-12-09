#include <bits/stdc++.h>
using namespace std;
int main()
{
    pair<int, int> p = {1, 5};
    cout << p.first << " ";
    cout << p.second << endl;
    
    pair<int, pair<char, int>> p1 = {1, {'a', 2}};
    cout << p1.first << " ";
    cout << p1.second.first << " ";
    cout << p1.second.second << endl;

    vector<pair<int, int>> v = {{1, 2}, {3, 4}, {5, 6}};
    v.push_back({7, 8}); // insert
    v.emplace_back(3, 9); // in-place object create
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}