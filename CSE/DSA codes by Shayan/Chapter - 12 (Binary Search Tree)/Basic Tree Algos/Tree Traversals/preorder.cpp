#include<bits/stdc++.h>
using namespace std;

// * Definition for a binary tree node.
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// Recursive Solution:
void f(TreeNode* node, vector<int>&res){
    if(!node)   return;
    res.push_back(node->val);
    f(node->left, res);
    f(node->right, res);
}

vector<int> preorder(TreeNode* root){  // root, left, right
    vector<int>res;
    f(root, res);
    return res;
}

// Iterative Solution:
vector<int> preorder(TreeNode* root){ // root, left, right
    vector<int>res;
    if(!root)   return res;
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top(); st.pop();
        res.push_back(node->val);
        if(node->right) st.push(node->right);
        if(node->left)  st.push(node->left);
    }
    return res;
}