#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF = (int)1e18;

int32_t main(){
    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n + 1, INF);
    dis[1] = 0;
    pq.push({0, 1});  // {dis, node}
    while(!pq.empty()){
        auto pr = pq.top();
        pq.pop();
        int d = pr.first, node = pr.second;
        for(auto ele : adj[node]){
            int nei = ele.first, wt = ele.second;
            if(d + wt < dis[nei]){
                dis[nei] = d + wt;
                pq.push({dis[nei], nei});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << dis[i] << ' ';
    cout << endl; return 0;
}

// Time complexity : O(E * log(V))


// DIJKSTRA_SSSP(G, s):
// 1. make an array dis[1 :: n] and fill all its indices with INF
// 2. dis[s] = 0
// 3. Min Heap of pairs Q = {}
// 4. INSERT(Q, {s, 0})
// 5. while Q != {}
// 6.     pr <- EXTRACT_MIN(Q)
// 7.     node <- pr[0], wt <- pr[1]
// 8.     for all pairs p that belong to G.Adj[node]
// 9.         nei = p[0], w = p[1]
// 10.       if dis[nei] > wt + w
// 11.            dis[nei] = wt + w
// 12.            INSERT(Q, {nei, dis[nei]})
// 13. for i = 1 to n 
// 14.    print dis[i]