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
    int maxDepthDFS(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        return max(maxDepthDFS(root->left), maxDepthDFS(root->right)) + 1;
    }
    int maxDepthBFS(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        queue<TreeNode *> q;
        q.push(root);
        int height = 0;
        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            height++;
        }
        return height;
    }
};