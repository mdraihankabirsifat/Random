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

TreeNode* LCA(TreeNode* root, TreeNode* u, TreeNode* v){
    int a = u->val, b = v->val;
    if(a > b)   swap(a, b);
    TreeNode* cur = root;
    while(cur){
        if(cur->val < a)    cur = cur->right;
        else if(cur->val > b) cur = cur->left;
        else return cur;
    }
    return nullptr;
}