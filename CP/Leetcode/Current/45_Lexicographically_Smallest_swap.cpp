// 2948
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define sajai(x) sort(x.begin(), x.end())

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &v, int k)
    {
        ll n = v.size();
        if (n == 1)
        {
            return v;
        }
        vector<vector<int>> a;
        for (int i = 0; i < n; i++)
        {
            a.pb({v[i], i});
        }
        sajai(a);
        for (int i = 0; i < n;)
        {
            int j = i;
            while (j + 1 < n && a[j + 1][0] - a[j][0] <= k)
            {
                j++;
            }
            vector<int> v1;
            for (int x = i; x <= j; x++)
            {
                v1.pb(a[x][1]);
            }
            sajai(v1);
            for (int x = i; x <= j; x++)
            {
                v[v1[x - i]] = a[x][0];
            }
            i = j + 1;
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {4, 52, 38, 59, 71, 27, 31, 83, 88, 10};
    string s1 = "";
    ll n = 14;
    Solution sol;
    v = sol.lexicographicallySmallestArray(v, n);
    out(v);
    return 0;
}