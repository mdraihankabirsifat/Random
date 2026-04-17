#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int u, v, w;
};

// Disjoint Set (Union-Find)
vector<int> parent;

int findSet(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findSet(parent[x]); // path compression
}

void unionSet(int a, int b)
{
    a = findSet(a);
    b = findSet(b);
    if (a != b)
        parent[a] = b;
}

int main()
{

    int n = 5; // number of vertices

    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 8}, {1, 2, 2}, {1, 3, 6}, {2, 3, 3}, {3, 4, 5}};

    // initialize disjoint sets
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // sort edges by weight
    sort(edges.begin(), edges.end(), [](Edge a, Edge b)
         { return a.w < b.w; });

    int mstCost = 0;

    // process edges
    for (auto e : edges)
    {

        // if adding edge does not create cycle
        if (findSet(e.u) != findSet(e.v))
        {

            unionSet(e.u, e.v); // connect components
            mstCost += e.w;

            cout << e.u << " - " << e.v << " : " << e.w << endl;
        }
    }

    cout << "MST cost = " << mstCost;

    return 0;
}

/*
Key Notes:

1. Problem:
   Find Minimum Spanning Tree (MST)

2. Idea (Greedy):
   Always pick the smallest weight edge.

3. Steps:
   - Start with each node as separate tree
   - Sort edges in increasing order
   - Add edge if it does NOT form a cycle

4. Cycle Detection:
   Use Disjoint Set (Union-Find)

5. If Find(u) ≠ Find(v):
   → safe to add edge

6. Stop when:
   MST has (V - 1) edges

7. Time Complexity:
   O(E log E) (sorting)

8. Why greedy works:
   Minimum edge between components is always safe
*/