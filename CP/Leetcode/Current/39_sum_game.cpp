// 1927
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    bool sumGame(string s)
    {
        int n = s.size(), s1 = 0, s2 = 0, a = 0, b = 0;
        for (int i = 0; i < n; i++)
        {
            if (i < n / 2)
            {
                if (s[i] == '?')
                    a++;
                else
                    s1 += s[i] - '0';
            }
            else
            {
                if (s[i] == '?')
                    b++;
                else
                    s2 += s[i] - '0';
            }
        }
        return ((a + b) & 1) || (s1 - s2) != (b - a) * 4.5;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s = "?3295???";
    Solution sol;
    cout << sol.sumGame(s);
    return 0;
}