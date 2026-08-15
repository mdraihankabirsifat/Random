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
        long long n, o = 0, e = 0;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] % 2)
            {
                o++;
            }
            else
            {
                e++;
            }
        }
        if (o * e)
        {
            sort(v.begin(), v.end());
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}