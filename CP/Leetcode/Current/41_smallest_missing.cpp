// 3718
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
    int missingMultiple(vector<int> &p, int k)
    {
        vector<int> v;
        int j = 1;
        while (k * j < 201)
        {
            v.pb(k * j);
            j++;
        }
         //out(v);
        vector<bool> v1(201);
        for (int i = 0; i < p.size(); i++)
        {
            v1[p[i]] = true;
        }
        int x;
        for (int i = 0; i < v.size(); i++)
        {
            if (!v1[v[i]])
            {
                x = v[i];
                break;
            }
        }
        return x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {42, 13, 99, 13, 71, 32, 64, 32, 63, 44, 6, 22, 8, 2, 55, 88, 43, 40, 71, 80, 95, 32, 46, 19};
    ll n = 44;
    Solution sol;
    cout << sol.missingMultiple(v, n);
    return 0;
}