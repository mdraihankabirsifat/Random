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
        long long n, d = 0;
        cin >> n;
        vector<pair<long long, long long>> p(n);
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].first >> p[i].second;
            d = d + abs(p[i].second - p[i].first);
        }
        vector<long long> a, b;
        for (int i = 0; i < n; i++)
        {
            a.push_back(p[i].first);
            b.push_back(p[i].second);
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        while (a.size() > 1 && b.size() > 1)
        {
            int min_a = a[0];
            int max_b = b[b.size() - 1];
            d = d + (max_b - min_a);
            for (int i = 0; i < n; i++)
            {
                if (p[i].first == a[0])
                {
                    for (int j = 0; j < b.size(); j++)
                    {
                        if (b[j] == p[i].second)
                        {
                            b.erase(b.begin() + j);
                            break;
                        }
                    }
                    p.erase(p.begin() + i);
                    break;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (p[i].second == b[b.size() - 1])
                {
                    for (int j = 0; j < a.size(); j++)
                    {
                        if (a[j] == p[i].first)
                        {
                            a.erase(a.begin() + j);
                            break;
                        }
                    }
                    p.erase(p.begin() + i);
                    break;
                }
            }
            a.erase(a.begin());
            b.pop_back();
        }
        cout << d << endl;
    }
    return 0;
}