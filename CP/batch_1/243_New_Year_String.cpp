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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (int i = 3; i < n; i++)
        {
            if (s[i - 3] == '2' && s[i - 2] == '0' && s[i - 1] == '2' && s[i] == '6')
            {
                a = 1;
            }
            if (s[i - 3] == '2' && s[i - 2] == '0' && s[i - 1] == '2' && s[i] == '5')
            {
                b = 1;
            }
        }
        if (!a && b)
        {
            cout << 1 << tata;
        }
        else
        {
            cout << 0 << tata;
        }
    }
    return 0;
}