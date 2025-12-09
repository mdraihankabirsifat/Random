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
        ll n, k, m = LONG_LONG_MIN;
        cin >> n >> k;
        vector<ll> a(n), b(n), p(n);
        loop(i, n)
        {
            cin >> a[i];
        }
        loop(i, n)
        {
            cin >> b[i];
        }
        loop(i, n)
        {
            p[i] = a[i];
            ll l = i - 1;
            while (l >= 0 && a[l] > 0)
            {
                p[i] += a[l];
                l--;
            }
            ll r = i + 1;
            while (r < n && a[r] > 0)
            {
                p[i] += a[r];
                r++;
            }
        }
        if (k % 2)
        {
            loop(i, n)
            {
                m = max(m, p[i] + b[i]);
            }
            cout << m << endl;
        }
        else
        {
            cout << *max_element(p.begin(), p.end()) << endl;
        }
    }
    return 0;
}