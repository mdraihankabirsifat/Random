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
        int n, a = 0, b = 0, f = 1;
        cin >> n;
        vector<int> v(n);
        map<int, int> m;
        vector<pair<int, int>> p;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            m[v[i]]++;
        }
        for (auto x : m)
        {
            p.push_back({x.second, x.first});
        }
        sort(p.rbegin(), p.rend());
        for (int i = 0; i < p.size(); i++)
        {
            int p2 = p[i].first, p1 = p[i].second;
            if (f)
            {
                a = a + p2 * ((p1 + 1) / 2);
                b = b + p2 * (p1 / 2);
            }
            else
            {
                a = a + p2 * (p1 / 2);
                b = b + p2 * ((p1 + 1) / 2);
            }
            if (p1 % 2 == 1)
            {
                f = !f;
            }
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}