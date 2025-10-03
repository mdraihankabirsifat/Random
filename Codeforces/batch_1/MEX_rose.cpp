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
        int n, k, c = 0, s = 0;
        cin >> n >> k;
        vector<int> v(n), v1(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == k)
            {
                c++;
            }
            if (v1[v[i]] == 0 && v[i] < k)
            {
                v1[v[i]] = 1;
            }
        }
        for (int i = 0; i < k; i++)
        {
            if (v1[i] == 0)
            {
                s++;
            }
        }
        if (s > c)
        {
            cout << s << "\n";
        }
        else
        {
            cout << c << "\n";
        }
    }
    return 0;
}