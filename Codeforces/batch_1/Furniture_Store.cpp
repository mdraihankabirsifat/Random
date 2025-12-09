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
        int n, c = 0, m = 101;
        cin >> n;
        vector<int> v(n + 1), v1, mn(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (m > v[i])
            {
                m = v[i];
            }
            mn[i] = m;
        }
        for (int i = 1; i < n; i++)
        {
            if (mn[i - 1] < v[i])
            {
                c++;
                v1.push_back(i + 1);
            }
        }
        cout << c << "\n";
        for (int i = 0; i < v1.size(); i++)
        {
            cout << v1[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}