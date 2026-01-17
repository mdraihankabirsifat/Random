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

void insert_bst(TreeNode* root, TreeNode*  node){
    if(!root || !node)  return;
    TreeNode* par = nullptr, *cur = root;
    while(cur){
        par = cur;
        if(node->val < cur->val) cur = cur->left;
        else cur = cur->right;
    }
    if(node->val < par->val){
        par->left = node;
        node->parent = par->left;
    }
    else {
        par->right = node;
        node->parent = par->right;
    }
}



