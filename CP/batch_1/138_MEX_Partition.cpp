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
        int n;
        cin >> n;
        vector<int> v(101, 0);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v[x]++;
        }
        if (!v[0])
        {
            cout << 0 << "\n";
        }
        else
        {
            for (int i = 1; i > 0; i++)
            {
                if (!v[i])
                {
                    cout << i << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}