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
        long long n, m, f = 0;
        cin >> n >> m;
        vector<int> v(m);
        for (int i = 0; i < m; i++)
        {
            cin >> v[i];
            if (i != 0 && v[i - 1] >= v[i])
            {
                f = 1;
            }
        }
        if (f)
        {
            cout << 1 << "\n";
        }
        else
        {
            //cout << "n: " << n << "\nv[m-1]: " << v[m - 1] << "\n";
            cout << n - v[m - 1] + 1 << "\n";
        }
    }
    return 0;
}