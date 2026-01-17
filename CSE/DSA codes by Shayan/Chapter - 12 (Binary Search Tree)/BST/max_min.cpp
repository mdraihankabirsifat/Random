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

TreeNode* max_bst(TreeNode* root){
    if(!root)   return nullptr;
    while(root->right)  root = root->right;
    return root;
}

TreeNode* min_bst(TreeNode* root){
    if(!root)   return nullptr;
    while(root->left)  root = root->left;
    return root;
}