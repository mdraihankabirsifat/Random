#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y) vector<vector<ll>> v(x, vector<int>(y))
#define tata '\n'
#define loop(i, n) for (ll i = 0; i < n; i++)
#define in(v) loop(i, v.size()) cin >> v[i]
#define out(v) loop(i, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, c = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        loop(i, n)
        {
            if (s[i] == '1')
            {
                ll m = i;
                for (int j = m + 1; j <= m + k; j++)
                {
                    i++;
                    if (s[j] == '1')
                    {
                        i--;
                        break;
                    }
                    else if (j == n)
                    {
                        break;
                    }
                }
            }
            else
            {
                c++;
            }
        }
        cout << c << tata;
    }
    return 0;
}