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
        long long n, s = 0, c = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] < 0)
            {
                v[i] = v[i] * -1;
                c++;
            }
            s = s + v[i];
        }
        sort(v.begin(), v.end());
        if (c % 2)
        {
            s = s - 2 * v[0];
        }
        cout << s << "\n";
    }
    return 0;
}