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
    vector<string> largestString(vector<int> &v)
    {
        int n = v.size();
        vector<string> ans(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 25; j++)
            {
                if (v[i] & (1 << j))
                {
                    ans[i] += char('a' + j);
                }
            }
            ans[i] += string(v[i] >> 25, 'z');
            reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {3, 9, 1};
    string s = "";
    ll n;
    Solution sol;
    vector<string> v1 = sol.largestString(v);
    out(v1);
    return 0;
}