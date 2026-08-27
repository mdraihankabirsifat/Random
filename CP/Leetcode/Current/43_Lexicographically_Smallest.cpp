// 3720
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
    string lexGreaterPermutation(string s, string p)
    {
        string ans;
        int n = s.size(), i = 0;
        vector<int> v(26);
        for (int j = 0; j < n; j++)
        {
            v[s[j] - 'a']++;
        }
        while (i < n && v[p[i] - 'a'])
        {
            ans += p[i];
            v[p[i] - 'a']--;
            i++;
        }
        // cout << ans << tata;
        while (true)
        {
            if (i < n)
            {
                for (ll c = p[i] - 'a' + 1; c < 26; c++)
                {
                    if (v[c])
                    {
                        // cout << c << tata;
                        ans += char('a' + c);
                        v[c]--;
                        for (int j = 0; j < 26; j++)
                        {
                            for (int k = 0; k < v[j]; k++)
                            {
                                ans += char('a' + j);
                            }
                        }
                        return ans;
                    }
                }
            }
            if (i == 0)
            {
                return "";
            }
            i--;
            v[ans.back() - 'a']++;
            ans.pop_back();
        }
        //return "";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {};
    string s1 = "leet", s2 = "code";
    ll n;
    Solution sol;
    cout << sol.lexGreaterPermutation(s1, s2);
    return 0;
}