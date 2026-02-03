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
        float n;
        cin >> n;
        if (n == 3)
        {
            cout << 3 << tata;
        }
        else if (n == 2)
        {
            cout << 2 << tata;
        }
        else
        {
            //cout << ceil(n / 2) << " " << floor(n / 2) << tata;
            cout << ceil(n / 2) - floor(n / 2) << tata;
        }
    }
    return 0;
}