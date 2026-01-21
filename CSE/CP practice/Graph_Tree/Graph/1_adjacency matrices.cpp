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
ll graph[N][N]; // O(N^2)

int main()
{
    ll n, m,i,j;
    cin >> n >> m; // n = vertices, m = edges
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
    }
    // i, j connected?, i, j > wt ?
    if (graph[i][j] == 1)
    {
        // connected
    }
}