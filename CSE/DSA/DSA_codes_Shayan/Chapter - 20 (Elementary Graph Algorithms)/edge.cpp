#include<bits/stdc++.h>
using namespace std;
const int N = (int)2e5 + 10;
vector<vector<int>>adj(N);
vector<int>color(N);
vector<int>start(N);
vector<int>finish(N);
vector<int>par(N);
int cur_time = 0;
int n;
map<pair<int, int>, string>mp;

void dfs(){
    for(int i = 1; i <= n; i++){
        color[i] = 0;
        par[i] = -1;
    }
    cur_time = 0;
    for(int i = 1; i <= n; i++){
        if(color[i] == 0){
            dfs_visit(i);
        }
    }
}

void dfs_visit(int node){
    color[node] = 1;
    cur_time = cur_time + 1;
    start[node] = cur_time;
    for(auto ele : adj[node]){
        if(!color[ele]){
            mp[{node, ele}] = "Tree Edge";
            par[ele] = node;
            dfs_visit(ele);
        }else if(color[ele] == 1){
            mp[{node, ele}] = "Back Edge";
        }else{
            if(finish[ele] < start[node]){
                mp[{node, ele}] = "Cross Edge";
            }else mp[{node, ele}] = "Forward Edge";
        }
    }
    color[node] = 2;
    finish[node] = ++cur_time;
}

int main(){
    cin >> n;
}