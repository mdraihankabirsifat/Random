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

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = numRows, m = s.size(), k = 0;
        vector<vector<char>> v(n, vector<char>(m));
        for (int j = 0; j < m; j++)
        {
            if (n == 1)
            {
                return s;
            }
            else if (j % (n - 1) == 0)
            {
                for (int i = 0; i < n; i++)
                {
                    v[i][j] = s[k];
                    k++;
                    if (k > m)
                    {
                        m = j + 1;
                        goto end;
                    }
                }
            }
            else
            {
                v[n - (j % (n - 1)) - 1][j] = s[k];
                k++;
                if (k > m)
                {
                    m = j + 1;
                    goto end;
                }
            }
        }
    end:;
        k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j])
                {
                    s[k] = v[i][j];
                    k++;
                }
            }
        }
        return s;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll n;
    cin >> n;
    cin >> s;
    Solution sol;
    cout << sol.convert(s, n);
    return 0;
}