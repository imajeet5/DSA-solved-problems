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
    TreeNode *searchBST(TreeNode *root, int val)
    {
        if (root == NULL)
        {
            return NULL;
        }
        if (val == root->val)
        {
            return root;
        }

        if (val < root->val)
        {
            return searchBST(root->left, val);
        }
        if (val > root->val)
        {
            return searchBST(root->right, val);
        }
    }
    TreeNode *searchBSTIterative(TreeNode *root, int val)
    {
        while (root != NULL)
        {
            if (root->val == val)
            {
                return root;
            }
            // if value is smaller then go to left 
            if (val < root->val )
            {
                root = root->left;
            }
            else
            {
                // otherwise go to right
                root = root->right;
            }
        }

        return NULL;
    }
};