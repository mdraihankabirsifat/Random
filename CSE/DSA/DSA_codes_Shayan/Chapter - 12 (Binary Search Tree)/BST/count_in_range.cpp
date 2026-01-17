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

int count_in_range(TreeNode* root, int l, int r){
    if(!root)   return 0;
    if(root->val > r){
        return count_in_range(root->left, l, r);
    }else if(root->val < l){
        return count_in_range(root->right, l, r);
    }else{
        return 1 + count_in_range(root->left, l, r) + 
        count_in_range(root->right, l, r);
    }
}