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
    int getMinimumDifference(TreeNode *root)
    {

        //first do the inorder traversal and convert the binary tree into array in ascending order
        stack<TreeNode *> s;
        vector<int> inorder;
        TreeNode *curr = root;

        // while current Node is not equal to null or stack is not empty
        while (curr != NULL || !s.empty())
        {
            while (curr != NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            // here curr is NULL, so we will pop the top element from the stack
            curr = s.top();
            s.pop();
            inorder.push_back(curr->val);
            curr = curr->right;
        }
        int minDiff = INT_MAX;
        for (int i = 1; i < inorder.size(); i++)
        {
            minDiff = min(minDiff, abs((inorder[i - 1], inorder[i])));
        }

        return minDiff;
    }
    int getMinimumDifference2(TreeNode *root)
    {
        vector<int> inorder;
        dfs(root, inorder);
        int minDiff = INT_MAX;
        for (int i = 1; i < inorder.size(); i++)
        {
            minDiff = min(minDiff, abs((inorder[i - 1] - inorder[i])));
        }

        return minDiff;
    }

    void dfs(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
        {
            return;
        }
        dfs(root->left, inorder);
        inorder.push_back(root->val);
        dfs(root->right, inorder);
    }
};