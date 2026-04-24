#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int>parent;
    vector<int>size;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 1; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int find(int x){  // O(alpha(n))
        if(x != parent[x]){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void make_union(int x, int y){  // O(alpha(n))
        int rootx = find(x), rooty = find(y);
        if(rootx == rooty)  return;
        if(size[rootx] < size[rooty]){
            size[rooty] += size[rootx];
            parent[rootx] = rooty;
        }else{
            size[rootx] += size[rooty];
            parent[rooty] = rootx;
        }
    }
};