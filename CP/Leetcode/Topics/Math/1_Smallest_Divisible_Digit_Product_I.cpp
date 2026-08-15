// https://leetcode.com/problems/smallest-divisible-digit-product-i/
/*
Problem: Smallest Divisible Digit Product I

Find the smallest integer at least n whose product of decimal digits
is divisible by t.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution
{
public:
    int smallestNumber(int n, int t)
    {
        for (int i = 0; i < 10; i++)
        {
            ll p = n + i, temp = 1;
            ll h = p;
            while (p)
            {
                temp *= p % 10;
                p = p / 10;
            }
            //cout << "temp: " << temp << tata;
            if (temp % t == 0)
            {
                return h;
            }
        }
        return 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, t;
    cin >> n >> t;
    Solution sol;
    cout << sol.smallestNumber(n, t);
    return 0;
}
