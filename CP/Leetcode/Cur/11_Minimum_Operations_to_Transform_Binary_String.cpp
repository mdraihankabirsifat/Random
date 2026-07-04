//https://leetcode.com/problems/minimum-operations-to-transform-binary-string/description/
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
    int minOperations(string s1, string s2)
    {
        string s3 = s1;
        string s4 = s2;
        int s = 0;
        if (s1.size() == 1 && s1[0] == '1' && s2[0] == '0')
        {
            return -1;
        }
        if (s1.size() == 1 && s1[0] == '0' && s2[0] == '1')
        {
            return 1;
        }
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0')
            {
                s1[i] = '0';
                s1[i + 1] = '0';
                s += 1;
            }
        }
        for (int i = 0; i < s1.size(); i = i + 2)
        {
            if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1') ||
                (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '1') ||
                (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0') ||
                (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '0') ||
                (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '1'))
            {
                s += 1;
            }
            else if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1'))
            {
                s += 2;
            }
            else if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1'))
            {
                s += 3;
            }
        }

        if (s1.size() % 2)
        {
            if (s1[s1.size() - 1] == '0' && s2[s1.size() - 1] == '1')
            {
                s += 1;
            }
            else if (s1[s1.size() - 1] == '1' && s2[s1.size() - 1] == '0')
            {
                s += 2;
            }
        }
        int p = s;
        s = 0;
        s1 = s3;
        s2 = s4;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0')
            {
                s1[i] = '0';
                s1[i + 1] = '0';
                s += 1;
            }
        }
        for (int i = 0; i < s1.size(); i = i + 2)
        {
            if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1') ||
                (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '1') ||
                (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0') ||
                (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '0') ||
                (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '1'))
            {
                s += 1;
            }
            else if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '0') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1'))
            {
                s += 2;
            }
            else if ((s1[i] == '1' && s1[i + 1] == '0' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '0' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '0' && s2[i + 1] == '1') ||
                     (s1[i] == '1' && s1[i + 1] == '1' && s2[i] == '1' && s2[i + 1] == '0') ||
                     (s1[i] == '0' && s1[i + 1] == '0' && s2[i] == '1' && s2[i + 1] == '1'))
            {
                s += 3;
            }
        }

        if (s1.size() % 2)
        {
            if (s1[s1.size() - 1] == '0' && s2[s1.size() - 1] == '1')
            {
                s += 1;
            }
            else if (s1[s1.size() - 1] == '1' && s2[s1.size() - 1] == '0')
            {
                s += 2;
            }
        }
        int l = min(s, p);
        return l;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1 = "11";
    string s2 = "00";
    Solution sol;
    cout << sol.minOperations(s1, s2);
    return 0;
}