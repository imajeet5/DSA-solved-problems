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
    void dfs(TreeNode *root, int low, int high, int &total)
    {
        if (root == NULL)
        {
            return;
        }

        if (root->val >= low && root->val <= high)
        {
            total += root->val;
        }
        /** 
         * Since this is a BST we go to left only is the current value is greater then the low,
         * bcz if the current value is smaller than low, then there is no point of traversing further as all other values to the left are smaller than low which will be out of range
         * same is the case with right side, only traverse the right side if the current value is smaller than the highest then only traverse to the right side
         */

        if (root->val > low)
            dfs(root->left, low, high, total);
        if (root->val < high)
            dfs(root->right, low, high, total);
    }

    void bfs(TreeNode *root, int low, int high, int &total)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto curr = q.front();
            q.pop();
            if (curr->val >= low && curr->val <= high)
            {
                total += curr->val;
            }
            if (curr->left && curr->val > low)
            {
                q.push(curr->left);
            }
            if (curr->right && curr->val < high)
            {
                q.push(curr->right);
            }
        }
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int total = 0;
        dfs(root, low, high, total);
        return total;
    }
};