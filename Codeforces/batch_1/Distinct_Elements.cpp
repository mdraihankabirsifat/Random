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
        int n, c = 1;
        cin >> n;
        vector<long long> v(n), v1(n);
        v[0] = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        for (int i = 1; i < n; i++)
        {
            if ((v1[i] - v1[i - 1]) > i)
            {
                v[i] = ++c;
            }
            else
            {
                v[i] = v[i - v1[i] + v1[i - 1]];
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}