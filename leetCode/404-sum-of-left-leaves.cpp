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
    int sumOfLeftLeaves(TreeNode *root)
    {
        int sum = 0;
        dfs(root, sum, "root");

        return sum;
    }
    void dfs(TreeNode *root, int &sum, string from)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->left == NULL && root->right == NULL && from == "left")
        {
            sum += root->val;
        }
        dfs(root->left, sum, "left");
        dfs(root->right, sum, "right");
    }
};