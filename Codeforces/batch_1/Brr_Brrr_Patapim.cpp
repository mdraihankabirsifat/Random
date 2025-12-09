#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        vector<int> p(2 * n + 1);
        vector<vector<int>> v(n + 1, vector<int>(n + 1));
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                cin >> v[i][j];
                p[i + j] = v[i][j];
            }
        }
        int sum = accumulate(p.begin() + 2, p.end(), 0);
        p[1] = (2 * n * (2 * n + 1) / 2) - sum;
        for (i = 1; i <= 2 * n; i++)
        {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}