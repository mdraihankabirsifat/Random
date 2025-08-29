#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n), v1(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v1[i] = v[i];
        }
        sort(v.begin(), v.end());
        if (v == v1 || k > 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}