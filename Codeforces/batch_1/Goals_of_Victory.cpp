#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, s = 0;
        cin >> n;
        vector<int> v(n - 1);
        for (int i = 0; i < n - 1; i++)
        {
            cin >> v[i];
            s = s + v[i];
        }
        cout << -1 * s << endl;
    }
    return 0;
}