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
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        map<long long, vector<long long>> m;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            v[i] = v[i] % k;
            m[v[i]].push_back(i + 1);
        }
        if (!m[0].empty())
        {
            for (int j = 0; j < m[0].size(); j++)
            {
                cout << m[0][j] << " ";
            }
        }
        for (auto it = m.rbegin(); it != m.rend(); it++)
        {
            if (it->first != 0)
            {
                for (int j = 0; j < it->second.size(); j++)
                {
                    cout << it->second[j] << " ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}