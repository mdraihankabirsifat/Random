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

vector<vector<int>>level_order(TreeNode* root){
    queue<TreeNode*>q1, q2;
    vector<vector<int>>res(1, vector<int>({}));
    q1.push(root);
    while(!q1.empty()){
        TreeNode* node = q1.front(); q1.pop();
        res.back().push_back(node->val);
        if(node->left)  q2.push(node->left);
        if(node->right) q2.push(node->right);
        if(q1.empty() && !q2.empty()){
            q1.swap(q2);
            res.push_back({});
        }
    }
    return res;
}