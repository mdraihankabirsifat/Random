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
        long long n, k, s = 0, f = 0, j = 0;
        cin >> n >> k;
        vector<long long> v(n), b(k);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            s = s + v[i];
        }
        for (int i = 0; i < k; i++)
        {
            cin >> b[i];
        }
        sort(v.begin(), v.end(), greater<long long>());
        sort(b.begin(), b.end());
        for (int i = 0; i < n; i++)
        {
            f = b[j] + f;
            if (f > n)
            {
                break;
            }
            s = s - v[f - 1];
            j++;
            if (j >= k)
            {
                break;
            }
            i = f - 1;
        }
        cout << s << "\n";
    }
    return 0;
}