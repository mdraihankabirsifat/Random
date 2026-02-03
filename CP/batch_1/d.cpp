#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    int t;
    cin >> t;
    while (t--)
    {
        long long n, a = -1;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int x : p)
        {
            int y = 1;
            for (int i = 0; i < n; i++)
            {
                if (v[i] % x != 0)
                {
                    y = 0;
                    break;
                }
            }
            if (!y)
            {
                a = x;
                break;
            }
        }
        cout << a << "\n";
    }
    return 0;
}