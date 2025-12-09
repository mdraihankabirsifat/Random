#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, h, k;
        cin >> n >> a;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 1)
            {
                h = i;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] == 1)
            {
                k = i;
                break;
            }
        }
        if (h - k + 1 > a)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}