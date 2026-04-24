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

bool is_complete(TreeNode* root){
    if(!root)   return true;
    queue<TreeNode*>q;
    q.push(root);
    bool null_found = false;
    while(!q.empty()){
        TreeNode* node = q.front(); q.pop();
        if(!node)   null_found = true;
        else{
            if(null_found)  return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}