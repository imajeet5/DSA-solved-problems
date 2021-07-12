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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> po;
        postOrder(root, po);
        return po;
    }
    void postOrder(TreeNode *root, vector<int> &po)
    {
        if (root == NULL)
        {
            return;
        }

        postOrder(root->left, po);
        postOrder(root->right, po);
        po.push_back(root->val);
    }

    vector<int> postorderTraversalIterative(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> s;
        stack<int> po;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *curr = s.top();
            s.pop();
            po.push(curr->val);
            if (curr->left)
                s.push(curr->left);
            if (curr->right)
                s.push(curr->right);
        }

        while (!po.empty())
        {
            int val = po.top();
            po.pop();
            ans.push_back(val);
        }

        return ans;
    }
};