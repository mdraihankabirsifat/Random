#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    TreeNode* left, *right;
    int val;
    TreeNode(int val){
        this->val = val;
        left = right = nullptr;
    }
};

bool is_full(TreeNode* root){
    if(!root)   return true;
    if((root->left && !root->right) || (root->right && !root->left)) return false;
    if(!(root->left) && !(root->right)) return true;
    return (is_full(root->left) && is_full(root->right)); 
}