#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;

int32_t main(){
    int n, m; cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> dis(n + 1, INF); dis[1] = 0;
    for(int i = 1; i < n; i++){
        for(auto ele : edges){
            int u = get<0>(ele), v = get<1>(ele), w = get<2>(ele);
            if(dis[u] != INF && dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
            }
        }
    }
    for(auto ele : edges){
        int u = get<0>(ele), v = get<1>(ele), w = get<2>(ele);
        if(dis[v] > dis[u] + w){
            cout << "NO\n";
            return 0;
        }
    }
    for(int i = 1; i <= n; i++) cout << dis[i] << ' ';
    cout << endl; return 0;
}


// BELLMAN_FORD_SSSP(G, s):
// 1. make an array dis[1 :: n] and fill it with INF
// 2. dis[s] = 0
// 3. for i = 1 to n - 1
// 4.    for all edges E = (u, v, w) that belong to G.E
// 5.         if dis[u] != INF and dis[v] > dis[u] + w
// 6.              dis[v] = dis[u] + w
// 7. for all edges E = (u, v, w) that belong to G.E
// 8.     if dis[v] != dis[u] + w 
// 9.        return false
// 10. return true