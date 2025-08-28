#include <bits/stdc++.h>
using namespace std;
int main()
{
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
        sort(v.begin(), v.end());
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
            {
                cout << "YES" << endl;
                f = 1;
                break;
            }
        }
        if (f == 0)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}