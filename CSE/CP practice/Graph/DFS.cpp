#include <bits/stdc++.h>
using namespace std;

void dfsUsingStack(vector<vector<int>> &graph, int start)
{
    int n = graph.size();
    vector<bool> visited(n, false);
    stack<int> st;

    // Push starting node to stack
    st.push(start);

    cout << "DFS Traversal: ";

    while (!st.empty())
    {
        // Pop node from stack
        int current = st.top();
        st.pop();

        // If not visited, process it
        if (!visited[current])
        {
            visited[current] = true;
            cout << current << " ";

            // Push all unvisited neighbors to stack
            // Note: We push in reverse order to maintain left-to-right traversal
            for (int i = graph[current].size() - 1; i >= 0; i--)
            {
                int neighbor = graph[current][i];
                if (!visited[neighbor])
                {
                    st.push(neighbor);
                }
            }
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Example graph representation using adjacency list
    // Graph:
    //   0 --- 1 --- 3
    //   |     |
    //   2 --- 4

    int nodes = 5;
    vector<vector<int>> graph(nodes);

    // Adding edges (undirected graph)
    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0, 4};
    graph[3] = {1};
    graph[4] = {1, 2};

    // Perform DFS starting from node 0
    dfsUsingStack(graph, 0);

    // Example with user input
    cout << "\nEnter number of nodes and edges: ";
    int n, m;
    cin >> n >> m;

    vector<vector<int>> userGraph(n);

    cout << "Enter " << m << " edges (format: u v):\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        userGraph[u].push_back(v);
        userGraph[v].push_back(u); // For undirected graph
    }

    cout << "Enter starting node: ";
    int start;
    cin >> start;

    dfsUsingStack(userGraph, start);

    return 0;
}