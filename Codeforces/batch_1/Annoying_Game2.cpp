#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define msort(x) sort(x.begin(), x.end())
#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), b(n), l(n),r(n);
        loop(i, n)
        {
            cin >> a[i];
        }
        loop(i, n)
        {
            cin >> b[i];
        }
        ll ms = a[0], cs = a[0];
        for (int i = 1; i < n; i++)
        {
            cs = max(a[i], cs + a[i]);
            ms = max(ms, cs);
        }

        if (k == 1 || k % 2 == 1)
        {
            ll c = ms;
            l[0] = a[0];
            for (int i = 1; i < n; i++)
            {
                l[i] = max(a[i], l[i - 1] + a[i]);
            }
            r[n - 1] = a[n - 1];
            for (int i = n - 2; i >= 0; i--)
            {
                r[i] = max(a[i], r[i + 1] + a[i]);
            }
            loop(i, n)
            {
                ll x1 = a[i] + b[i];
                ll x2 = x1;
                if (i > 0)
                    x2 = max(x2, x1 + l[i - 1]);
                if (i < n - 1)
                    x2 = max(x2, x1 + r[i + 1]);
                if (i > 0 && i < n - 1)
                    x2 = max(x2, x1 + l[i - 1] + r[i + 1]);
                c = max(c, x2);
            }
            cout << c << endl;
        }
        else
        {
            cout << ms << endl;
        }
    }
    return 0;
}