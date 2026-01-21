#include <bits/stdc++.h>
using namespace std;

// Binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// -------- Traversals --------

// Preorder: Node -> Left -> Right
void preorder(TreeNode *root)
{
    if (!root)
        return;               // base case
    cout << root->val << " "; // work at node
    preorder(root->left);
    preorder(root->right);
}

// Inorder: Left -> Node -> Right
void inorder(TreeNode *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Postorder: Left -> Right -> Node
void postorder(TreeNode *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// -------- Counting & Values --------

// Total nodes in tree
int countNodes(TreeNode *root)
{
    if (!root)
        return 0; // empty tree
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count leaf nodes (no children)
int countLeaves(TreeNode *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
}

// Sum of all node values
int sumNodes(TreeNode *root)
{
    if (!root)
        return 0;
    return root->val + sumNodes(root->left) + sumNodes(root->right);
}

// Height / maximum depth of tree
int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main()
{
    /*
            1
           / \
          2   3
         / \
        4   5
    */

    // build sample tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // traversals
    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    // basic DFS results
    cout << "Total nodes: " << countNodes(root) << endl;
    cout << "Leaf nodes: " << countLeaves(root) << endl;
    cout << "Sum of nodes: " << sumNodes(root) << endl;
    cout << "Max depth: " << maxDepth(root) << endl;

    return 0;
}
