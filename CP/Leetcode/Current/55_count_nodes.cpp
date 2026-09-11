#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define tata "\n"
#define loop(i, j, n) for (ll i =reit j;inders i < n; i++)
#define in(v) loop(i, 0, v.size()) cin >> v[i]
#define out(v) loop(i, 0, v.size()) cout << v[i] << " "
ll result = 0;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<ll> traverseSubtree(TreeNode *root)
{
    if (root == nullptr)
    {
        return {0, 0};
    }
    vector<ll> left = traverseSubtree(root->left);
    vector<ll> right = traverseSubtree(root->right);
    ll sum = left[0] + right[0] + root->val;
    ll count = left[1] + right[1] + 1;
    if (sum / count == root->val)
    {
        result++;
    }
    return {sum, count};
}

class Solution
{
public:
    int averageOfSubtree(TreeNode *root)
    {
        traverseSubtree(root);
        return result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /*
             4
            / \
           8   5
          / \   \
         0   1   6
    */

    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(8);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(1);
    root->right->right = new TreeNode(6);

    Solution sol;
    cout << sol.averageOfSubtree(root) << tata; // 5

    return 0;
}