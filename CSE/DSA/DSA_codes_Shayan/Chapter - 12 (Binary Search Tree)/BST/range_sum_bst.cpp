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

int range_sum_bst(TreeNode* root, int l, int r){ // sum of all ele = [l, r];
    if(!root)   return 0;
    if(root->val > r){
        return range_sum_bst(root->left, l, r);
    }else if(root->val < l){
        return range_sum_bst(root->right, l, r);
    }else{
        return root->val + range_sum_bst(root->left, l, r) +
        range_sum_bst(root->right, l, r);
    }
}