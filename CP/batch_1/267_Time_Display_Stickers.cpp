#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define rsort(a) sort(a.begin(), a.end(), greater<>())
#define ulta(a) reverse(a.begin(), a.end())
#define mucho(a, j) a.erase(a.begin() + j)
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
        ll n, c = 0;
        string s;
        cin >> n >> s;
        vector<ll> v(10);
        for (int i = 0; i < n; i++)
        {
            v[s[i] - '0']++;
        }
    here:;
        ll g = 0, h = 0;
        if (v[0])
        {
            v[0]--;
            g = 1;
        }
        else if (v[1] > 1)
        {
            v[1] -= 2;
            h = 1;
            g = -1;
        }
        if (g == 0 && h == 0)
        {
            goto end;
        }
        if (g && !h)
        {
            for (int i = 9; i >= 0; i--)
            {
                if (v[i])
                {
                    v[i]--;
                    g = -1;
                    break;
                }
            }
        }
        if (g == -1)
        {
            for (int i = 5; i >= 0; i--)
            {
                if (v[i])
                {
                    v[i]--;
                    g = -2;
                    break;
                }
            }
        }
        if (g == -2)
        {
            for (int i = 9; i >= 0; i--)
            {
                if (v[i])
                {
                    v[i]--;
                    g = -3;
                    break;
                }
            }
        }
        if (g == -3)
        {
            c++;
        }
        goto here;
    end:;
        cout << c << endl;
    }
    return 0;
}