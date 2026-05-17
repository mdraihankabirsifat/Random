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
        vector<int> v(n), v1(n), v2(2 * n + 1), v3(2 * n + 1);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        for (int i = 0; i < n; i++)
        {
            int x = v[i];
            int count = 0;
            int j = i;
            while (j < n && v[j] == x)
            {
                count++;
                j++;
            }
            v2[x] = max(v2[x], count);
            i = j - 1;
        }
        for (int i = 0; i < n; i++)
        {
            int x = v1[i];
            int count = 0;
            int j = i;
            while (j < n && v1[j] == x)
            {
                count++;
                j++;
            }
            v3[x] = max(v3[x], count);
            i = j - 1;
        }
        int c = -1;
        for (int i = 0; i < v3.size(); i++)
        {
            v2[i] = v2[i] + v3[i];
            if (v2[i] > c)
            {
                c = v2[i];
            }
        }
        cout << c << endl;
    }
    return 0;
}