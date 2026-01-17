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

void kth_smallest(TreeNode* node, int &k, int &res){
    if(!node)   return;
    kth_smallest(node->left, k, res);
    k--;
    if(k == 0){
        res = node->val;
        return;
    }
    kth_smallest(node->right, k, res);
}