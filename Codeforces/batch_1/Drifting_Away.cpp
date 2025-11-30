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
        string s;
        cin >> s;
        bool k = true;
        int n = s.size(), l = 0, r = 0, d = 0;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && s[i] == '*' && (s[i - 1] == '*' || s[i - 1] == '>'))
                k = false;
            if (i < (n - 1) && s[i] == '*' && (s[i + 1] == '*' || s[i + 1] == '<'))
                k = false;
            if (i > 0 && s[i] == '<' && s[i - 1] == '>')
                k = false;
            if (i < (n - 1) && s[i] == '>' && s[i + 1] == '<')
                k = false;
            if (s[i] == '>')
                r++;
            if (s[i] == '<')
                l++;
            if (s[i] == '*')
                d++;
        }
        if (k)
        {
            int c = 0;
            c = max(l + d, r + d);
            cout << c << tata;
        }
        else
            cout << -1 << tata;
    }
    return 0;
}