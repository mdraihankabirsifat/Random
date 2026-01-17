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

void transplant(TreeNode*&root, TreeNode* &u, TreeNode* &v){ 
    // v completely takes the location of u, but doesn't remove u instantly
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

TreeNode* findpredecessor(TreeNode* node){
    TreeNode* cur = node->left;
    while(cur->right)  cur = cur->right;
    return cur;
}

TreeNode* deleteNode(TreeNode* &root, TreeNode* &node){
    if(!root || !node)  return root;
    if(!node->left){
        transplant(root, node, node->right);
    }else if(!node->right){
        transplant(root, node, node->left);
    }else{
        TreeNode* pred = findpredecessor(node);
        if(pred != node->left){
            transplant(root, pred, pred->left);
            pred->left = node->left;
            node->left->parent = pred;
        }
        transplant(root, node, pred);
        pred->right = node->right;
        node->right->parent = pred;
    }
    delete node;
    return root;
}