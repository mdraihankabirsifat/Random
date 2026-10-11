#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata
vector<string> v;

void solve(string &s, int idx, int a, int b)
{
    if (a == 0 && b == 0)
    {
        v.pb(s);
        return;
    }
    // cout << s << tata;
    if (a > 0)
    {
        s[idx] = '(';
        solve(s, idx + 1, a - 1, b);
    }
    if (b > a)
    {
        s[idx] = ')';
        solve(s, idx + 1, a, b - 1);
    }
}

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        v.clear();
        string s(2 * n, {});
        solve(s, 0, n, n);
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> p;
    string s = "";
    ll n = 7;
    Solution sol;
    p = sol.generateParenthesis(n);
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << tata;
    }
    //cout << v.size();
    return 0;
}