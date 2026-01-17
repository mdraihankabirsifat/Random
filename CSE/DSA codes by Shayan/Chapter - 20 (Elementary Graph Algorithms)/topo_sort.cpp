#include<bits/stdc++.h>
using namespace std;
const int N = (int)1e5 + 10;
vector<vector<int>>adj(N);
vector<int>par(N);
vector<int>col(N);
vector<int>start(N);
vector<int>finish(N);
int n = 1000;
int cur_time = 0;
vector<int>topo;

void dfs(){
    for(int i = 1; i <= n; i++){
        col[i] = 0;
        par[i] = -1;
    }
    for(int i = 1; i <= n; i++){
        if(!col[i]){
            dfs_visit(i);
        }
    }
}

void dfs_visit(int node){
    cur_time = cur_time + 1;
    start[node] = cur_time;
    col[node] = 1;
    for(auto ele : adj[node]){
        if(!col[ele]){
            par[ele] = node;
            dfs_visit(ele);
        }
    }
    cur_time = cur_time + 1;
    finish[node] = cur_time;
    col[node] = 2;
    topo.push_back(node);
}

vector<int> topo_sort(){
    reverse(topo.begin(), topo.end());
    return topo;
}