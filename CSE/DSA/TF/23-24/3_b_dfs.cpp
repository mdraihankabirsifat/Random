#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100];
int color[100]; // 0 = WHITE, 1 = GRAY, 2 = BLACK
int parent[100];

void iterativeDFS(int source)
{
    stack<int> st;

    st.push(source);
    parent[source] = -1;

    while (!st.empty())
    {
        int u = st.top();

        if (color[u] == 0)
        {
            color[u] = 1; // discovered
            cout << u << " becomes GRAY\n";
        }

        bool foundWhiteChild = false;

        for (int v : adj[u])
        {
            if (color[v] == 0)
            {
                cout << "Tree Edge: " << u << " -> " << v << endl;
                parent[v] = u;
                st.push(v);
                foundWhiteChild = true;
                break;
            }
            else if (color[v] == 1)
            {
                cout << "Back Edge: " << u << " -> " << v << endl;
            }
            else if (color[v] == 2)
            {
                cout << "Forward/Cross Edge: " << u << " -> " << v << endl;
            }
        }

        if (!foundWhiteChild)
        {
            color[u] = 2; // finished
            cout << u << " becomes BLACK\n";
            st.pop();
        }
    }
}

int main()
{
    /*
        Vertex mapping:
        r=0, s=1, t=2, u=3, v=4, w=5, x=6, y=7
    */

    adj[1] = {0, 5}; // s -> r, w
    adj[0] = {4};    // r -> v
    adj[2] = {5};    // t -> w
    adj[3] = {2, 6}; // u -> t, x
    adj[5] = {6};    // w -> x
    adj[6] = {2};    // x -> t
    adj[7] = {3, 6}; // y -> u, x

    for (int i = 0; i < 8; i++)
    {
        color[i] = 0;
        parent[i] = -1;
    }

    iterativeDFS(1); // start from s

    return 0;
}

/*
Key Notes:

1. DFS explores as deep as possible before backtracking.

2. Recursive DFS uses function call stack.
   Iterative DFS explicitly uses stack.

3. Colors:
   WHITE = undiscovered
   GRAY  = discovered but not finished
   BLACK = finished

4. Stack behavior:
   - Push a WHITE child when found.
   - If no WHITE child remains, pop the node.

5. Edge types:
   - WHITE vertex  => Tree Edge
   - GRAY vertex   => Back Edge
   - BLACK vertex  => Forward/Cross Edge

6. Time Complexity:
   O(V + E)

7. Space Complexity:
   O(V), for stack, color array, and parent array.
*/