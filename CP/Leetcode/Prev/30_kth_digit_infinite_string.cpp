#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"

class Solution
{
public:
    int kthDigit(ll k)
    {
        ll l = 1, a = 1;
        while (a <= (k - 1) / (9 * l))
        {
            k -= 9 * a * l;
            l++;
            a *= 10;
        }
        k--;
        ll n = a + k / l;
        ll pos = k % l;
        ll b = n / 10;
        if (b % 2)
        {
            n = b * 10 + (9 - n % 10);
        }
        return to_string(n)[pos] - '0';
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k = 4;
    Solution sol;
    cout << sol.kthDigit(k);
    return 0;
}