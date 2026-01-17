#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    TreeNode* left, *right, *parent;
    int val;
    TreeNode(int val){
        this->val = val;
        left = right = parent = nullptr;
    }
};

// Recursive
TreeNode* search_bst(TreeNode* root, int key){
    if(!root || root->val == key)   return root;
    if(root->val > key) search_bst(root->left, key);
    else search_bst(root->right, key);
}

// Iterative;
TreeNode* search_bst(TreeNode* root, int key){
    while(root){
        if(root->val == key)    return root;
        else if(root->val > key)  root = root->left;
        else root = root->right;
    }
    return root;
}

