#include<bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
vector<vector<int>>adj(N);
vector<int>vis(N);

void bfs(int source){
    queue<int>q;
    vis[source] = 1;
    q.push(source);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto ele : adj[node]){
            if(!vis[ele]){
                vis[ele] = 1;
                q.push(ele);
            }
        }
    }
}