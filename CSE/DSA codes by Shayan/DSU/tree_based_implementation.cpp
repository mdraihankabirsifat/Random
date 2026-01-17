#include<bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector<int>parent;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int x){  // O(n)
        while(x != parent[x])   x = parent[x];
        return x;
    }
    void make_union(int x, int y){  // O(n)
        int rootx = find(x), rooty = find(y);
        if(rootx == rooty)    return;
        parent[rooty] = rootx;
    }
};

