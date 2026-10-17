#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, c = 0, p = 0, ans = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<ll> v;
        ll a = n / 2 - k;
        for (char ch : s)
        {
            if (ch == '(')
            {
                v.pb(c);
                while (p < v.size() && v[p] < c - k)
                {
                    p++;
                }
                ll cur = v.size() - p;
                ans = max(ans, min(a, cur));
                if (c <= k)
                {
                    ans = max(ans, k + min(a, (ll)v.size()));
                }
            }
            else
            {
                v.pop_back();
                p = min(p, (ll)v.size());
                c++;
            }
        }
        cout << ans << tata;
    }
    return 0;
}
