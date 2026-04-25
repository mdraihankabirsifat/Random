#include <iostream>
using namespace std;

struct treeNode
{
    int item;
    struct treeNode *left;
    struct treeNode *right;
};

struct treeNode *root;

/*
    clone(node):
    Recursively creates a copy of the binary tree
    rooted at node and returns the root of the copy.
*/
struct treeNode *clone(struct treeNode *node)
{
    // Base case: empty tree/subtree
    if (node == NULL)
        return NULL;

    // Create a new node
    struct treeNode *newNode = new struct treeNode;

    // Copy current node's data
    newNode->item = node->item;

    // Recursively copy left and right subtrees
    newNode->left = clone(node->left);
    newNode->right = clone(node->right);

    return newNode;
}

/*
Key Notes:

1. This is a binary tree, not necessarily a binary search tree.

2. clone(node) returns the root pointer of the copied tree.

3. Base case:
   If node == NULL, return NULL.

4. Recursive idea:
   - Create a new node.
   - Copy node->item.
   - Recursively clone left subtree.
   - Recursively clone right subtree.

5. Original tree remains unchanged because we create new nodes using new.

6. Time Complexity:
   O(n), because every node is visited once.

7. Space Complexity:
   O(h) recursion stack,
   where h = height of tree.
   Extra O(n) space is needed for the newly copied tree.
*/