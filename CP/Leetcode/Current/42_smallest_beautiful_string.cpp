// 2904
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();
        vector<int> pref(n + 1);
        pref[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                pref[i + 1] = pref[i] + 1;
            }
            else
            {
                pref[i + 1] = pref[i];
            }
        }
        // 0 1 1 2
        // out(pref);
        int l = 1, r = k, t = INT_MAX, a = 0, b = 0, p = 0;
        while (l <= n && r <= n)
        {
            if (s[l - 1] == '0')
            {
                if (l == r)
                {
                    r++;
                }
                l++;
            }
            else if (pref[r] - pref[l - 1] < k)
            {
                r++;
            }
            else if (pref[r] - pref[l - 1] == k)
            {
                if (t == r - l + 1)
                {
                    string s1 = s.substr(a - 1, b - a + 1);
                    string s2 = s.substr(l - 1, r - l + 1);
                    if (s2 < s1)
                    {
                        a = l;
                        b = r;
                        p = 1;
                    }
                }
                else if (t > r - l + 1)
                {
                    a = l;
                    b = r;
                    p = 1;
                    t = r - l + 1;
                    cout << a << " " << b << tata;
                }
                l++;
                r++;
            }
            else if (pref[r] - pref[l - 1] > k)
            {
                l++;
            }
        }
        if (p)
        {
            if (a == b)
            {
                return "1";
            }
            return s.substr(a - 1, b - a + 1);
        }
        else
        {
            return {};
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {};
    string s = "110101000010110101";
    ll n = 3;
    Solution sol;
    cout << sol.shortestBeautifulSubstring(s, n);
    return 0;
}