#include <bits/stdc++.h>
using namespace std;
#define tata "\n"

struct Node
{
    int key;             // Value stored in the node
    struct Node *left;   // Pointer to left child
    struct Node *right;  // Pointer to right child
    struct Node *parent; // Pointer to parent node
};

// --- BST Operations (O(h) Complexity) ---

// 1. Search for a node with key k in the BST rooted at x
Node *treeSearch(Node *x, int k)
{
    if (x == nullptr || k == x->key)
        return x; // Return node if found or nullptr if not found
    if (k < x->key)
        return treeSearch(x->left, k); // Search left subtree
    else
        return treeSearch(x->right, k); // Search right subtree
}

// 2. Find the node with the minimum key in the BST rooted at x
Node *treeMinimum(Node *x)
{
    while (x->left != nullptr)
        x = x->left; // Go as left as possible
    return x;
}

// 3. Find the node with the maximum key in the BST rooted at x
Node *treeMaximum(Node *x)
{
    while (x->right != nullptr)
        x = x->right; // Go as right as possible
    return x;
}

// 4. Find the successor of node x (the node with the next higher key)
Node *treeSuccessor(Node *x)
{
    if (x->right != nullptr)
        return treeMinimum(x->right); // Successor is leftmost node in right subtree
    Node *y = x->parent;
    // Go up until we find a node that is a left child; its parent is the successor
    while (y != nullptr && x == y->right)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

// 5. Find the predecessor of node x (the node with the next lower key)
Node *treePredecessor(Node *x)
{
    if (x->left != nullptr)
        return treeMaximum(x->left); // Predecessor is rightmost node in left subtree
    Node *y = x->parent;
    // Go up until we find a node that is a right child; its parent is the predecessor
    while (y != nullptr && x == y->left)
    {
        x = y;
        y = y->parent;
    }
    return y;
}

// 6. Insert a new node with key k into the BST
void treeInsert(Node *&root, int k)
{
    Node *z = new Node{k, nullptr, nullptr, nullptr}; // New node to insert
    Node *y = nullptr;                                // Parent of x
    Node *x = root;                                   // Start from root

    // Find the correct position for the new node
    while (x != nullptr)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y; // Set parent pointer
    if (y == nullptr)
        root = z; // Tree was empty, new node is root
    else if (z->key < y->key)
        y->left = z; // Insert as left child
    else
        y->right = z; // Insert as right child
}

// --- Main Function ---

int main()
{
    Node *root = nullptr;

    // Inserting keys to build the following BST:
    //           15
    //         /    \
    //        6      18
    //       / \    /  \
    //      3   7  17  20
    //     / \   \
    //    2   4  13
    //           /
    //          9
    int keys[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
    for (int k : keys)
    {
        treeInsert(root, k);
    }

    // Test searching for a node
    Node *found = treeSearch(root, 13);
    if (found)
        cout << "Search Found: " << found->key << endl;

    // Test finding minimum and maximum
    cout << "Tree Minimum: " << treeMinimum(root)->key << endl;
    cout << "Tree Maximum: " << treeMaximum(root)->key << endl;

    // Test finding the successor of 13
    Node *succ = treeSuccessor(found);
    if (succ)
        cout << "Successor of 13: " << succ->key << endl;

    // Test finding the predecessor of 6
    Node *node6 = treeSearch(root, 6);
    Node *pred = treePredecessor(node6);
    if (pred)
        cout << "Predecessor of 6: " << pred->key << endl;

    return 0;
}