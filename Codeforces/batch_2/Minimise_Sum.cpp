#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        if (v[0] > v[1])
        {
            cout << v[0] + v[1] << endl;
        }
        else
        {
            cout << 2 * v[0] << endl;
        }
    }
    return 0;
}