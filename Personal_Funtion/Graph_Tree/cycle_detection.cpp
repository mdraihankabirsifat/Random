// Cycle Detection in Directed Graph using DFS
#include <vector>
using namespace std;

// Assumes adjacency list g is defined globally or passed as parameter
// vector<vector<int>> g;

vector<int> visD, inStack;
bool hasCycle = false;

void dfs_cycle_directed(int u, vector<vector<int>>& g){
    visD[u] = 1;
    inStack[u] = 1;

    for(int v : g[u]){
        if(!visD[v]){
            dfs_cycle_directed(v, g);
        }
        else if(inStack[v]){ 
            hasCycle = true; // back-edge in directed graph
        }
    }

    inStack[u] = 0;
}

// Helper function to detect cycle in directed graph
bool detectCycle(int n, vector<vector<int>>& g){
    visD.assign(n+1, 0);
    inStack.assign(n+1, 0);
    hasCycle = false;
    
    for(int i=1; i<=n; i++){
        if(!visD[i]){
            dfs_cycle_directed(i, g);
            if(hasCycle) return true;
        }
    }
    
    return hasCycle;
}
