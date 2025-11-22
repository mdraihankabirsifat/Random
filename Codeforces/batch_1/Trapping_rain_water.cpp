#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define msort(x) sort(x.begin(), x.end())
#define endl '\n'
#define loop(i, n) for (int i = 0; i < n; i++)
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int water = 0;
        for (int i = 0; i < n; i++)
        {
            int leftMax = 0, rightMax = 0;
            for (int j = 0; j <= i; j++)
                leftMax = max(leftMax, height[j]);
            for (int j = i; j < n; j++)
                rightMax = max(rightMax, height[j]);
            water += min(leftMax, rightMax) - height[i];
        }
        return water;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    Solution sol;
    cout << sol.trap(v);
    return 0;
}