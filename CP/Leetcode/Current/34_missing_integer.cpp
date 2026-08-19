//3471. Find the Largest Almost Missing Integer
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
#define sajai(x) sort(x.begin(), x.end())
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define bit(n) __builtin_popcountll(n)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_set<int> s;
        s.insert(nums.begin(), nums.end());
        if (n == k)
        {
            return boro(nums);
        }
        else if (n == s.size())
        {
            if (k == 1)
            {
                return boro(nums);
            }
            else
            {
                return max(nums[0], nums[n - 1]);
            }
        }
        else
        {
            vector<int> v(51), v1(n);
            for (int i = 0; i < n; i++)
            {
                v[nums[i]]++;
            }
            if (k == 1)
            {
                v1 = nums;
                sort(v1.begin(), v1.end(), greater<int>());
                for (int i = 0; i < n; i++)
                {
                    if (v[v1[i]] == 1)
                    {
                        return v1[i];
                    }
                }
            }
            else
            {
                int a = nums[0];
                if (v[a] == 1)
                {
                    for (int i = 1; i < k; i++)
                    {
                        if (nums[i] == a)
                        {
                            a = -1;
                        }
                    }
                }
                else
                {
                    a = -1;
                }
                int b = nums[n - 1];
                if (v[b] == 1)
                {
                    for (int i = n - 2; i > n - k - 1; i--)
                    {
                        if (nums[i] == b)
                        {
                            // cout << b << " " << nums[i] << " " << i << tata;
                            b = -1;
                        }
                    }
                }
                else
                {
                    b = -1;
                }
                // cout << a << " " << b << tata;
                if (a == -1 && b != -1)
                {
                    // cout << 1 << " ";
                    return b;
                }
                else if (a != -1 && b == -1)
                {
                    // cout << 2 << " ";
                    return a;
                }
                else if (a != -1 && b != -1)
                {
                    return max(a, b);
                }
            }
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k = 5;
    vector<int> v = {1, 4, 8, 7, 5, 2, 2, 9, 10};
    Solution sol;
    cout << sol.largestInteger(v, k);
    return 0;
}