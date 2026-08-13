#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<int>> v(x, vector<int>(y))
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define rsort(a) sort(a.begin(), a.end(), greater<>())
#define ulta(a) reverse(a.begin(), a.end())
#define mucho(a, j) a.erase(a.begin() + j)
#define choto(a) *min_element(a.begin(), a.end())
#define boro(a) *max_element(a.begin(), a.end())
#define jog(a) accumulate(a.begin(), a.end(), 0LL)
#define bit(n) __builtin_popcountll(n)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << tata
#define no cout << "NO" << tata

class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        int n = edges.size();
        vector<int> v(n + 1);
        for (int i = 0; i < n; i++)
        {
            v[edges[i][0]]++;
            v[edges[i][1]]++;
        }
        for (int i = 1; i < n + 2; i++)
        {
            if (v[i] == n)
            {
                return i;
            }
        }
        return 0;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<vector<int>> v(3, vector<int>(2));
    v[0][0] = 1;
    v[0][1] = 2;
    v[1][0] = 2;
    v[1][1] = 3;
    v[2][0] = 4;
    v[2][1] = 2;
    Solution sol;
    cout << sol.findCenter(v);
    return 0;
}