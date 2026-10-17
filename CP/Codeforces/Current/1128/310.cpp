#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define jog(a) accumulate(a.begin(), a.end(), 0LL)
#define bit(n) __builtin_popcountll(n)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        if (n == 1)
        {
            cout << 0 << tata;
            continue;
        }
        cout << (n + 1) / 2 << tata;
        if (n == 2)
        {
            cout << "1 1" << tata;
            continue;
        }
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            if (i == 0)
            {
                cout << "1 2" << tata;
            }
            else if (i == (n + 1) / 2 - 1)
            {
                if (n % 2)
                {
                    cout << 2 * i << " " << n << tata;
                }
                else
                {
                    cout << 2 * i << " " << n -1 << tata;
                }
            }
            else
            {
                cout << 2 * i << " " << 2 * i + 2 << tata;
            }
        }
    }
    return 0;
}
