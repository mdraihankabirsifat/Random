#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &x:v)
    {
        cin >> x.first >> x.second;
    }
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}