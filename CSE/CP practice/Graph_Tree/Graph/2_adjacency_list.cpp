#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define jora(p, n) pair<ll, ll> p(n)
#define sajai(x) sort(x.begin(), x.end())
#define arr(v, x, y) vector<vector<ll>> v(x, vector<int>(y))
#define loop(i, j, n) for (ll i = j; i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define tata "\n"
using namespace std;
const int N = 1e3 + 10;
vector<pair<int, int>> graph2[N]; // O(N+M)

int main()
{
    int n, m;
    cin >> n >> m; // n = vertices, m = edges
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph2[v1].pb({v2, wt});
        graph2[v2].pb({v1, wt});
    }
    // Print adjacency list
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ": ";
        for (auto p : graph2[i])
        {
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    }
    // Example: check if two nodes are connected
    int u, v;
    cout << "Enter two nodes to check connection: ";
    cin >> u >> v;
    bool connected = false;
    for (auto p : graph2[u])
    {
        if (p.first == v)
        {
            connected = true;
            break;
        }
    }
    if (connected)
        yes;
    else
        no;
}