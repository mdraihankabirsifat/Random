#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, c = 0;
        cin >> n >> x;
        if (n == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            if (i == n - 1 && x != n)
            {
                v[i] = x;
            }
            else if (i != x)
            {
                v[i] = c++;
            }
            else
            {
                v[i] = ++c;
                c++;
            }
            // cout << c << " ";
        }
        // cout << "\n";
        for (auto u : v)
        {
            cout << u << " ";
        }
        cout << "\n";
    }
    return 0;
}