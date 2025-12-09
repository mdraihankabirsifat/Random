#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, a;
    cin >> n;
    vector<int> nums(n, -1);
    nums[0] = 0;
    long long ans = 0, sums = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        sums = ((sums + a) % n + n) % n;
        ans = ans + ++nums[sums];
    }
    cout << ans;
    return 0;
}