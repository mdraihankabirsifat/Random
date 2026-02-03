#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            k = __gcd(k, abs(v[i] - i));
        }
        cout << k << endl;
    }
    return 0;
}