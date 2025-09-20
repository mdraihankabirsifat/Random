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
        long long n, a = 0, b = 0, f = 1;
        cin >> n;
        vector<long long> v(n);
        unordered_map<long long, long long> f1;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            f1[v[i]]++;
        }
        vector<pair<long long, long long>> p;
        p.reserve(f1.size());
        for (auto &x : f1)
        {
            p.push_back({x.first, x.second});
        }
        sort(p.begin(), p.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b)
             { return a.second > b.second; });
        for (int i = 0; i < p.size(); i++)
        {
            long long p1 = p[i].first, p2 = p[i].second;
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
