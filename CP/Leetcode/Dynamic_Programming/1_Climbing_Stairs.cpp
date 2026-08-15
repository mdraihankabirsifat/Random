// https://leetcode.com/problems/climbing-stairs/
/*
Problem: Climbing Stairs

Given a staircase with n steps, count the distinct ways to reach the top
when each move climbs either one or two steps.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vr(v, x) vector<ll> v(x)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        else if (n == 2)
        {
            return 2;
        }
        else
        {
            int a = 1, b = 2, s = 0;
            for (int i = 3; i <= n; i++)
            {
                s = a + b;
                a = b;
                b = s;
            }
            return s;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vr(v, n);
        in(v);
    }
    return 0;
}
