#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> graph(n + 1);
        vector<int> deg(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, x, y;
            cin >> u >> v >> x >> y;
            if (x > y)
            {
                graph[u].push_back(v);
                deg[v]++;
            }
            else
            {
                graph[v].push_back(u);
                deg[u]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (int v : graph[u])
            {
                deg[v]--;
                if (deg[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        vector<int> ans(n + 1);
        int value = n;
        for (int x : topo)
        {
            ans[x] = value--;
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}