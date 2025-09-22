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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> s(n);
        vector<int> f(m + 1);
        bool p = true;
        for (int i = 0; i < n; ++i)
        {
            int l;
            cin >> l;
            s[i].resize(l);
            for (int j = 0; j < l; ++j)
            {
                cin >> s[i][j];
                f[s[i][j]]++;
            }
        }
        for (int i = 1; i <= m; ++i)
        {
            if (f[i] == 0)
            {
                p = false;
                break;
            }
        }
        if (!p)
        {
            cout << "NO\n";
            continue;
        }
        int c2 = 0;
        for (int i = 0; i < n; ++i)
        {
            bool c1 = false;
            for (int x : s[i])
            {
                if (f[x] == 1)
                {
                    c1 = true;
                    break;
                }
            }
            if (!c1)
            {
                c2++;
            }
        }
        if (c2 >= 2)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}