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

// Predecessor -> Node with the largest key smaller than that of Node;
// Successor -> Node with the smallest key larget than that of Node;

TreeNode* predecessor(TreeNode* node){
    if(!node)   return nullptr;
    if(node->left){
        TreeNode* temp = node->left;
        while(temp->right)  temp = temp->right;
        return temp;
    }
    TreeNode* cur = node, *par = node->parent;
    while(par && par->left == cur){
        cur = par;
        par = cur->parent;
    }
    return par;
}

TreeNode* successor(TreeNode* node){
    if(!node)   return nullptr;
    if(node->right){
        TreeNode* temp = node->right;
        while(temp->left)   temp = temp->left;
        return temp;
    }
    TreeNode* cur = node, *par = cur->parent;
    while(par && par->right == cur){
        cur = par;
        par = cur->parent;
    }
    return par;
}

