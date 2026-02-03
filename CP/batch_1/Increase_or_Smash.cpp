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
        int n, c = 0;
        cin >> n;
        vector<int> v(n), p(101);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (!p[v[i]])
            {
                c++;
                p[v[i]] = 1;
            }
        }
        cout << 2 * c - 1 << "\n";
    }
    return 0;
}