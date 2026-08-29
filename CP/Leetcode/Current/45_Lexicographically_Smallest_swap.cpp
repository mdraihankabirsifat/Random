// 3734
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "

class Solution
{
public:
    vector<int> lexicographicallySmallestArray(vector<int> &v, int k)
    {
        // 1,3,5,8,9
        ll n = v.size();
        if (n == 1)
        {
            return v;
        }
        for (int i = n - 1; i > 0; i--)
        {
            for (int j = 0; j < i; j++)
            {
                if (abs(v[j] - v[i] <= k) && v[i] < v[j])
                {
                    swap(v[j], v[i]);
                }
            }
        }
        return v;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {1};
    string s1 = "";
    ll n = 1;
    Solution sol;
    v = sol.lexicographicallySmallestArray(v, n);
    out(v);
    return 0;
}