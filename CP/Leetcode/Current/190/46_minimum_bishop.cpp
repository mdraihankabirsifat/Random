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
    int minBishopMoves(vector<int> &s, vector<int> &t)
    {
        if (s[0] == t[0] && s[1] == t[1])
        {
            return 0;
        }
        if ((s[0] + s[1]) % 2 != (t[0] + t[1]) % 2)
        {
            return -1;
        }
        if (abs(s[0] - t[0]) == abs(s[1] - t[1]))
        {
            return 1;
        }
        return 2;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v1 = {8, 1}, v2 = {1, 8};
    string s = "";
    ll n;
    Solution sol;
    cout << sol.minBishopMoves(v1, v2);
    return 0;
}