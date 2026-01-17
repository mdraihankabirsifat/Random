#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    int n;
    vector<int>parent;
    DSU(int n){
        this->n = n;
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int x){ // O(1)
        return parent[x];
    }
    void make_union(int x, int y){ // O(n)
        if(parent[x] == parent[y])  return;
        for(int i = 1; i <= n; i++){
            if(parent[i] == parent[x])  parent[i] = parent[y];
        }
    }
};