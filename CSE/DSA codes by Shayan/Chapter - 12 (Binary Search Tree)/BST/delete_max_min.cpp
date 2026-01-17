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

void delete_min(TreeNode* &root){
    if(!root->left){
        TreeNode* temp = root->right;
        delete root;
        root = temp;
        return;
    }
    TreeNode* cur = root, *par = nullptr;
    while(cur->left){
        par = cur;
        cur = cur->left;
    }
    par->left = cur->right;
    if(cur->right)  cur->right->parent = par->left;
    delete cur;
}

void delete_max(TreeNode*&root){
    if(!root->right){
        TreeNode* cur = root->left;
        delete root;
        root = cur;
        return;
    }
    TreeNode* cur = root, *par = nullptr;
    while(cur->right){
        par = cur;
        cur = cur->right;
    }
    par->right = cur->left;
    if(cur->left)   cur->left->parent = par->right;
    delete cur;
}

