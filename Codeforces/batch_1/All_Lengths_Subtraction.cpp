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
        int n, f = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (v[i] < v[i - 1] && v[i] < v[i + 1])
            {
                cout << "NO" << "\n";
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            cout << "YES" << "\n";
        }
    }
    return 0;
}