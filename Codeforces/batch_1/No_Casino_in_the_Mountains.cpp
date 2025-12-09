#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, c = 0, m = 0;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] != 0)
            {
                c = 0;
            }
            if (v[i] == 0)
            {
                c++;
            }
            if (c == k)
            {
                m++;
                c = 0;
                i++;
            }
        }
        cout << m << endl;
    }
    return 0;
}