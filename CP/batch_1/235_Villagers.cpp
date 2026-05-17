#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, s = 0;
        cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        for (int i = n-1; i >0; i = i - 2)
        {
            s = s + v[i];
        }
        if (n % 2 != 0)
        {
            s = s + v[0];
        }
        cout << s << endl;
    }
    return 0;
}