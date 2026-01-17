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

void inorder(TreeNode*cur, TreeNode*&head, TreeNode*&prev){
    if(!cur)   return;
    inorder(cur->left, head, prev);
    if(!prev){
        head = cur;
        cur->left = nullptr;
    }else{
        cur->left = prev;
        prev->right = cur;
    }
    prev = cur;
    inorder(cur->right, head, prev);
}


TreeNode* bst_to_dll(TreeNode* root){
    if(!root) return nullptr;
    TreeNode* head = nullptr, *prev = nullptr;
    TreeNode* cur = root;
    inorder(cur, head, prev);
    if(prev)    prev->right = nullptr;
    return head;
}