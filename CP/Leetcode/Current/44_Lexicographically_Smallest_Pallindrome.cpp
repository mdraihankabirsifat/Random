// 3734
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)

class Solution
{
public:
    string lexPalindromicPermutation(string s, string p)
    {
        string ans, mid;
        int n = s.size(), i = 0;
        int m = n / 2;
        vector<int> v(26);
        for (int j = 0; j < n; j++)
        {
            v[s[j] - 'a']++;
        }
        if (n % 2)
        {
            int c1 = 0;
            for (int i = 0; i < 26; i++)
            {
                if (v[i] % 2)
                {
                    c1++;
                    mid += char(i + 'a');
                }
                v[i] /= 2;
            }
            if (c1 != 1)
            {
                return "";
            }
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (v[i] % 2)
                {
                    return "";
                }
                else
                {
                    v[i] /= 2;
                }
            }
        }
        while (i < m && v[p[i] - 'a'])
        {
            ans += p[i];
            v[p[i] - 'a']--;
            i++;
        }
        if (i == m)
        {
            string s1 = ans;
            reverse(s1.begin(), s1.end());
            s1 = ans + mid + s1;
            if (s1 > p)
            {
                return s1;
            }
        }
        // cout << ans << tata;
        while (true)
        {
            if (i < m)
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
                        string s1 = ans;
                        reverse(s1.begin(), s1.end());
                        ans += mid + s1;
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
        // return "";
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {};
    string s1 = "baba", s2 = "abba";
    ll n;
    Solution sol;
    cout << sol.lexPalindromicPermutation(s1, s2);
    return 0;
}