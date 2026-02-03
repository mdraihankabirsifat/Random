#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long n, d, l, p, q, c = 0;
    cin >> n >> d;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    l = n - 1;
    while (n != 0)
    {
        p = v[l];
        n--;
        q = n;
        for (int i = 0; i <= q; i++)
        {
            if (i != 0)
            {
                p = p + v[l];
                n--;
            }
            if (p > d)
            {
                c++;
                break;
            }
        }
        l--;
    }
    cout << c << "\n";
    return 0;
}