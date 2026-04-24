#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>&adj, queue<int>&q, vector<int>&par, vector<int>&h){
    while(!q.empty()){
        int node = q.front(); q.pop();
        for(auto ele : adj[node]){
            h[ele] = h[node] + 1;
            q.push(ele);
        }
    }
}

int height(vector<int>&par){
    int n = par.size();
    vector<int>h(n, 0);
    int root;
    vector<vector<int>>adj(n);
    for(int i = 0; i < n; i++){
        if(par[i] == -1){
            root = i;
        }
        else adj[par[i]].push_back(i);
    }
    queue<int>q;
    q.push(root);
    bfs(adj, q, par, h);
    int ans = -1;
    for(int i = 0; i < n; i++)  ans = max(ans, h[i]);
    return ans;
}