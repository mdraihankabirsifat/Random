#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    TreeNode* left, *right, *parent, *suc, *pre;
    int val;
    TreeNode(int val){
        this->val = val;
        left = right = parent = nullptr;
        suc = pre = nullptr;
    }
};

void inorder(TreeNode*& cur, TreeNode* &prev){
    if(!cur)    return;
    inorder(cur->left, prev);
    cur->pre = prev;
    if(prev) prev->suc = cur;
    prev = cur;
    inorder(cur->right, cur);
}

void compute_predecessor_successor(TreeNode* root){
    TreeNode* dummy = nullptr;
    inorder(root, dummy);
}

