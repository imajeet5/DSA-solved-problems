
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int dfs(TreeNode *root, int sum)
    {
        if (root == NULL)
        {
            return 0;
        }
        // we will calculate the sum upto this node
        sum = (sum << 1) + root->val;
        // if it is a leaf node, then we will return sum upto this node
        if (root->left == NULL && root->right == NULL)
        {
            return sum;
        }
        // we will find the sum from the left and sum from the right
        return dfs(root->left, sum) + dfs(root->right, sum);
    }

    int sumRootToLeaf(TreeNode *root)
    {
        return dfs(root, 0);
    }
};