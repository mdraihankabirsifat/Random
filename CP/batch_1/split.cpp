#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define msort(x) sort(x.begin(), x.end())
#define endl '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, q;
        cin >> n >> m >> q;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
        msort(a);
        for (int i = 1; i <= q; i++)
        {
            int b;
            cin >> b;
            int k = upper_bound(a.begin(), a.end(), b) - a.begin();
            if (k == 0)
                cout << a[0] - 1 << ' ';
            else if (k == m)
                cout << n - a[m - 1] << ' ';
            else
                cout << (a[k] - a[k - 1]) / 2 << ' ';
        }
        cout << endl;
    }
    return 0;
}