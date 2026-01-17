#include<bits/stdc++.h>
using namespace std;

// For full or complete binary tree

class TreeNode{
    public:
    TreeNode* left, *right, *parent;
    int val;
    TreeNode(int val){
        this->val = val;
        left = right = parent = nullptr;
    }
};

int height(TreeNode* root){  // Time complexity = O(n) // Chain structure;
    if(!root)   return 0;
    return 1 + max(height(root->left), height(root->right));
}