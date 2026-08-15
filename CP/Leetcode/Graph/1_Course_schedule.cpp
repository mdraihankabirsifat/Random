/*
Problem: Course Schedule

Given a number of courses and prerequisite pairs, determine whether
all courses can be completed without a dependency cycle.
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vr(v, x) vector<ll> v(x)
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]

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
