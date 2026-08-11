#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define boro(a) *max_element(a.begin(), a.end())
class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int n = nums.size(), s = nums[0];
        vector<bool> v(2501);
        for (int i = 0; i < n; i++)
        {
            v[nums[i]] = true;
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] - nums[i] == 1)
            {
                s += nums[i + 1];
            }
            else
            {
                break;
            }
        }
        ll j = s;
        while (1)
        {
            if (!v[j])
            {
                return j;
            }
            else
            {
                j++;
            }
        }
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    vector<int> v;
    v = {39};
    Solution sol;
    cout << sol.missingInteger(v);
    return 0;
}