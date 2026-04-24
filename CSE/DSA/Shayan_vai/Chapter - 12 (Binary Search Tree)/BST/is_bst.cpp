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

bool is_bst(TreeNode* root){
    if(!root)   return true;
    if(root->left && root->left->val > root->val)   return false;
    if(root->right && root->right->val < root->val)    return false;
    return is_bst(root->left) && is_bst(root->right);
}