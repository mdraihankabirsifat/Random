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
        long long n, m, x, y;
        cin >> n >> m >> x >> y;
        vector<int> v(n), v1(m);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> v1[i];
        }
        cout << n + m << endl;
    }
    return 0;
}