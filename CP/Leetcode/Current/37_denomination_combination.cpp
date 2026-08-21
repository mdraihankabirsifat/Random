// 3116
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define sajai(x) sort(x.begin(), x.end())
#define tata "\n"

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        sajai(coins);
        vector<int> v;
        for (int c : coins)
        {
            bool p = false;
            for (int x : v)
            {
                if (c % x == 0)
                {
                    p = true;
                    break;
                }
            }
            if (!p)
            {
                v.pb(c);
            }
        }
        ll n = v.size();
        auto ck = [&](ll mid)
        {
            ll t = 0;
            for (int i = 1; i <= n; i++)
            {
                int q = (1 << i) - 1;
                while (q < (1 << n))
                {
                    ll x = 1;
                    for (int j = 0; j < n; j++)
                    {
                        if ((q >> j) & 1)
                        {
                            x = lcm(x, v[j]);
                        }
                    }
                    if (i % 2 == 1)
                    {
                        t += mid / x;
                    }
                    else
                    {
                        t -= mid / x;
                    }
                    int c = q & (-q);
                    int r = q + c;
                    q = (((r ^ q) >> 2) / c) | r;
                }
            }
            return t >= k;
        };
        ll low = k;
        ll high = 1LL * v[0] * k;
        while (low < high)
        {
            ll mid = low + (high - low) / 2;
            if (ck(mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    Solution sol;
    // cout << sol.;
    return 0;
}