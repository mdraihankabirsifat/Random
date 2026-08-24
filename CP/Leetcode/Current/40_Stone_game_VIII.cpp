// 1872
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Solution
{
public:
    int stoneGameVIII(vector<int> &v)
    {
        int n = v.size();
        for (int i = 1; i < n; i++)
        {
            v[i] += v[i - 1];
        }
        int x = v[n - 1];
        for (int i = n - 2; i > 0; i--)
        {
            x = max(x, v[i] - x);
        }
        return x;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {-1, 2, -3, 4, -5};
    Solution sol;
    cout << sol.stoneGameVIII(v);
    return 0;
}