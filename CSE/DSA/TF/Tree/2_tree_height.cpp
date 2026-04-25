#include <iostream>
#include <queue>
using namespace std;

struct treeNode
{
    int item;
    treeNode *left;
    treeNode *right;
};

/*
    Height using BFS (Level Order Traversal)
*/
int heightBFS(treeNode *root)
{
    if (root == NULL)
        return -1; // empty tree

    queue<treeNode *> q;
    q.push(root);

    int h = -1;

    while (!q.empty())
    {
        int size = q.size();

        for (int i = 0; i < size; i++)
        {
            treeNode *v = q.front();
            q.pop();

            if (v->left != NULL)
                q.push(v->left);

            if (v->right != NULL)
                q.push(v->right);
        }

        h++; // finished one level
    }

    return h;
}

int main()
{
    // Example usage can be added if needed
    return 0;
}

/*
==========================
Answer (Theory + Notes)
==========================

1. What is a Tree?

A tree is a connected, acyclic graph with a designated root node.

Properties:
- Exactly one path between any two nodes.
- No cycles.
- If there are n nodes, there are (n-1) edges.

----------------------------------------

2. Height of a Tree:

Height = maximum number of edges from root to any leaf.

----------------------------------------

3. Algorithm Idea (BFS / Level Order):

- Use a queue.
- Process nodes level by level.
- Each level traversal increases height by 1.

----------------------------------------

4. Key Steps:

1. If root is NULL → return -1
2. Push root into queue
3. While queue is not empty:
   - Process all nodes in current level
   - Push their children
   - Increase height

----------------------------------------

5. Time Complexity:

Each node is:
- Enqueued once
- Dequeued once

⇒ Time Complexity = Θ(n)

----------------------------------------

6. Space Complexity:

Queue stores at most one level

⇒ Space = O(w)

where w = maximum width of the tree
Worst case = O(n)

----------------------------------------

7. Why BFS works:

Because BFS processes nodes level by level,
which directly corresponds to height counting.
*/