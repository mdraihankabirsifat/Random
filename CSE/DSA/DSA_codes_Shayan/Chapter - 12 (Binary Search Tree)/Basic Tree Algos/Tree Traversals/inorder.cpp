#include<bits/stdc++.h>
using namespace std;


// Definition for a binary tree node.
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Recursive Solution :

void f(TreeNode* node, vector<int>&res){
    if(!node)   return;
    f(node->left, res);
    res.push_back(node->val);
    f(node->right, res);
}

vector<int> inorder(TreeNode* root){ // left, root, right
    vector<int> res;
    if(!root)   return res;
    f(root, res);
    return res;
}

// Iterative Solution :

vector<int> inorder(TreeNode* root){ // left, root, right
    vector<int>res;
    if(!root)   return res;
    TreeNode* node = root;
    stack<TreeNode*>st;
    while(true){
        if(node){
            st.push(node);
            node = node->left;
        }else{ // left subtree is complete;
            if(st.empty())  break;
            TreeNode* cur_node = st.top(); st.pop();
            res.push_back(cur_node->val);
            node = node->right;
        }
    }
    return res;
}
 