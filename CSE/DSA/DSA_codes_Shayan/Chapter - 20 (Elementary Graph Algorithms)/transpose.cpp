#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>>adj(n + 1);
    for(int i = 1; i <= m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<vector<int>>adj1(n + 1);
    vector<int>out(n + 1), in(n + 1);
    for(int i = 1; i <= n; i++){ // O(V + E)
        for(auto ele : adj[i]){
            adj1[ele].push_back(i);
        }
    }
    for(int i = 1; i <= n; i++){
        in[i] = adj[i].size();
        out[i] = adj1[i].size();
        cout << in[i] << ' ' << out[i] << '\n';
    }
    return 0;
}