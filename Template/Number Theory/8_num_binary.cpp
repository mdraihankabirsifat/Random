#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define tata "\n"

string toBinary(ll n)
{
    if (n == 0)
    {
        return "0";
    }
    string ans = "";
    while (n > 0)
    {
        ans += char('0' + (n & 1));
        n >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n;
    cin >> n;
    cout << toBinary(n) << tata;
    return 0;
}