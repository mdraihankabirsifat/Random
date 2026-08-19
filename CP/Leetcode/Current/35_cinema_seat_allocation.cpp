#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define sajai(x) sort(x.begin(), x.end())

class Solution
{
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reservedSeats)
    {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < reservedSeats.size(); i++)
        {
            m[reservedSeats[i][0]].pb(reservedSeats[i][1]);
        }
        int c = (n - m.size()) * 2;
        for (auto x : m)
        {
            vector<int> v(11, 1);
            for (auto i : x.second)
            {
                v[i] = 0;
            }
            if (v[2] && v[3] && v[4] && v[5])
            {
                c++;
                if (v[6] && v[7] && v[8] && v[9])
                {
                    c++;
                    continue;
                }
            }
            else if (v[4] && v[5] && v[6] && v[7])
            {
                c++;
            }
            else if (v[6] && v[7] && v[8] && v[9])
            {
                c++;
            }
        }
        return c;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n = 3;
    vector<vector<int>> v = {{1, 2}, {1, 3}, {1, 8}, {2, 6}, {3, 1}, {3, 10}};
    Solution sol;
    cout << sol.maxNumberOfFamilies(n, v);
    return 0;
}