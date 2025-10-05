#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin() + 1, v.end() - 1);
    v.pop_back();
    int sz=v.size();
    for (int i = 0; i < sz; i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    return 0;
}