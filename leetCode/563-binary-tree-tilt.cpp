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
    int findTilt(TreeNode *root)
    {
        int totalTilt = 0;
        dfs(root, totalTilt);
        return totalTilt;
    }

    int dfs(TreeNode *root, int totalTile)
    {

        if (root == NULL)
        {
            return 0;
        }

        int leftSum = dfs(root->left, totalTile);
        int rightSum = dfs(root->right, totalTile);
        int currentTilt = abs(leftSum - rightSum);
        totalTile += currentTilt;
        return leftSum + rightSum + root->val;
    }
};