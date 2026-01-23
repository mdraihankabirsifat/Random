#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y) vector<vector<ll>> v(x, vector<int>(y))
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define tata "\n"
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if ((n & (n - 1)) == 0)
        {
            cout << -1 << tata;
            continue;
        }
        vector<ll> v(n + 1);
        if (n % 2 != 0)
        {
            v[1] = 1;
            for (ll i = 2; i <= n; i += 2)
            {
                v[i] = i + 1;
                v[i + 1] = i;
            }
            swap(v[1], v[n]);
        }
        else
        {
            v[1] = n;
            v[n] = 1;
            for (ll i = 2; i < n; i += 2)
            {
                v[i] = i + 1;
                v[i + 1] = i;
            }
            loop(i, 2, n + 1)
            {
                if ((v[1] ^ i) <= v[1])
                {
                    swap(v[1], v[i]);
                    break;
                }
            }
        }
        loop(i, 1, n + 1)
        {
            cout << v[i] << " ";
        }
        cout << tata;
    }
    return 0;
}