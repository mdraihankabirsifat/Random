#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void f(TreeNode* root){
    vector<int>preorder, inorder, postorder;
    stack<pair<TreeNode*, int>>st;
    st.push({root, 1});
    while(!st.empty()){
        auto &pr = st.top();
        TreeNode* node = pr.first;
        int &nums = pr.second;
        if(nums == 1){
            preorder.push_back(node->val);
            pr.second++;
            if(node->left)  st.push({node->left, 1});
        }else if(nums == 2){
            inorder.push_back(node->val);
            pr.second++;
            if(node->right) st.push({node->right, 1});
        }else{
            postorder.push_back(node->val);
            st.pop();
        }
    }
    for(auto ele : preorder)    cout << ele << ' '; cout << endl;
    for(auto ele : inorder) cout << ele << ' '; cout << endl;
    for(auto ele : postorder)   cout << ele << ' '; cout << endl;
}


// This approach effectively simulates recursion using a stack and status codes. 
// 1) Pre-order: The node is added to the preorder_result when its status is 1,
// meaning it is visited before any of its children are explored.

// 2) In-order: The node is added to inorder_result when its status is 2, 
// after its left subtree has been processed but before its right subtree.

// 3) Post-order: The node is added to postorder_result when its status is 3, 
// which is after both its left and right subtrees have been processed.