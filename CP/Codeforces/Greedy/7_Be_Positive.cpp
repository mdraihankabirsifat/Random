// https://codeforces.com/problemset/problem/2149/A
/*
Problem: Be Positive

Replace zeros by ones and, if necessary, change one -1 so the array's
sum and product are both positive using the fewest operations.
*/

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
        int n, s = 0, m = 0;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] == 0)
            {
                s++;
            }
            if (v[i] == -1)
            {
                m++;
            }
        }
        if (m % 2 != 0)
        {
            s = s + 2;
        }
        cout << s << "\n";
    }
    return 0;
}
