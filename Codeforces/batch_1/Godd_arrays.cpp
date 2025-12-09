#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, s = 0, c = 0;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 1)
            {
                c++;
            }
            s = s + v[i];
        }
        if (n > 1 && s >= c + n)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}