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
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }
        // if it is a leaf node the return the node
        if (root->left == NULL && root->right == NULL)
        {
            return root;
        }
        //otherwise change the pointer to the left and right side
        TreeNode *left = invertTree(root->right);
        TreeNode *right = invertTree(root->left);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode *invertTreeBFS(TreeNode *root)
    {
        if (root == NULL)
        {
            return root;
        }

        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *curr = q.front();
            // we will do swapping operation for every node
            TreeNode *temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
        }

        return root;
    }
};