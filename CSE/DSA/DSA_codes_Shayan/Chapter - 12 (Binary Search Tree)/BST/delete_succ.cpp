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

void transplant(TreeNode* &root, TreeNode* u, TreeNode* v){
    if(!u->parent){
        root = v;
    }else{
        if(u->parent->left == u){
            u->parent->left = v;
            if(v)   v->parent = u->parent;
        }else{
            u->parent->right = v;
            if(v)   v->parent = u->parent;
        }
    }
}

TreeNode* findSuccessor(TreeNode* node){
    TreeNode* cur = node->right;
    while(cur->left)    cur = cur->left;
    return cur;
}

TreeNode* deleteNode(TreeNode* &root, TreeNode* &node){
    if(!node->left){
        transplant(root, node, node->right);
    }else if(!node->right){
        transplant(root, node, node->left);
    }else{
        TreeNode* succ = findSuccessor(node);
        if(succ != node->right){
            transplant(root, succ, succ->right);
            succ->right = node->right;
            node->right->parent = succ;
        }
        transplant(root, node, succ);
        succ->left = node->left;
        node->left->parent = succ;
    }
    delete node;
    return root;
}