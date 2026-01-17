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

void conquer(vector<int>&a, vector<int>&b){
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    vector<int>temp;
    while(i < n && j < m){
        if(a[i] < b[j]) temp.push_back(a[i++]);
        else temp.push_back(b[j++]);
    }
    while(i < n)    temp.push_back(a[i++]);
    while(j < m)    temp.push_back(a[j++]);
    a.swap(temp);
}

TreeNode* array_to_bst(vector<int>&a, int l, int r){
    if(l > r)   return nullptr;
    int mid = (l + r) / 2;
    TreeNode* root = new TreeNode(a[mid]);
    root->left = array_to_bst(a, l, mid - 1);
    root->right = array_to_bst(a, mid + 1, r);
    return root;
}