#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define vr(v, x) vector<ll> v(x)
#define vrr(v, x, y) vector<vector<ll>> v(x, vector<ll>(y))
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
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> d(n, 0);
        vector<int> a;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            d[prerequisites[i][0]]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (d[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int t = q.front();
            a.push_back(t);
            q.pop();
            for (int i = 0; i < adj[t].size(); i++)
            {
                d[adj[t][i]]--;
                if (d[adj[t][i]] == 0)
                {
                    q.push(adj[t][i]);
                }
            }
        }
        return a.size() == n;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vr(v, n);
        in(v);
    }
    return 0;
}