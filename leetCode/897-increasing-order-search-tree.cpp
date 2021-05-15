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
    void inorder(TreeNode *root, vector<TreeNode *> &v)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        // the logic is to do the inorder traversal of the tree
        // and add each node to the to the array in order
        vector<TreeNode *> v;

        inorder(root, v);

        int n = v.size() - 1;
        for (int i = 0; i < n; i++)
        {
            v[i]->right = v[i + 1];
            v[i]->left = NULL;
        }

        v[n]->left = NULL;
        v[n]->right = NULL;

        return v[0];
    }
};