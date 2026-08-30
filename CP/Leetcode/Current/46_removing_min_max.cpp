// 2091
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i = j; i < n; i++)

class Solution
{
public:
    int minimumDeletions(vector<int> &v)
    {
        int n = v.size(), m1 = 0, m2 = 0, mn = v[0], mx = v[0], c = 0;
        if (n == 1)
        {
            return 1;
        }
        for (int i = 0; i < n; i++)
        {
            if (mn > v[i])
            {
                m1 = i;
                mn = v[i];
            }
            if (mx < v[i])
            {
                m2 = i;
                mx = v[i];
            }
        }
        m1++;
        m2++;
        // cout << m1 << " " << m2 << tata;
        int a = max(m1, m2), b = max(n - m1 + 1, n - m2 + 1), p = n - abs(m1 - m2) + 1;
        // cout << a << " " << b << " " << p << tata;
        return min(a, min(b, p));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> v = {-87, 60, -30, -67, 74, 55, 76, -53};
    string s = "";
    ll n;
    Solution sol;
    cout << sol.minimumDeletions(v);
    return 0;
}