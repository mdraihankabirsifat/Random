#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long ps = 0, ans = 0;
    map<long long, int> sum;
    sum[0] = 1;
    for (int i = 0; i < n; i++)
    {
        ps = ps + v[i];
        ans = ans + sum[ps - x];
        sum[ps]++;
    }
    cout << ans << endl;
}