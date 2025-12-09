// BFS to find shortest distance from source
#include <vector>
#include <queue>
using namespace std;

// Assumes adjacency list g is defined globally or passed as parameter
// vector<vector<int>> g;

vector<int> BFS(int src, int n, vector<vector<int>>& g){
    vector<int> dist(n+1, -1);
    queue<int> q;

    dist[src] = 0;
    q.push(src);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : g[u]){
            if(dist[v] == -1){
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
