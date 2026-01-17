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

TreeNode* array_to_bst(vector<int>&a, int l, int r){
    if(l > r)   return nullptr;
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(a[mid]);
    root->left = array_to_bst(a, l, mid - 1);
    root->right = array_to_bst(a, mid + 1, r);
    return root;
}