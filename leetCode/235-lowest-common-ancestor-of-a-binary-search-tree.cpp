#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // if root value is greater then both the node value
        if (root->val > max(p->val, q->val))
        {
            // then we will move toward left bcz both the node will be left of the current node
            return lowestCommonAncestor(root->left, p, q);
        }
        //else
        if (root->val < min(p->val, q->val))
        {
            // then we will move towards right bcz both the node will be on the right side of the tree
            return lowestCommonAncestor(root->right, p, q);
        }

        // root->val in btw both the node value, then we have found the lowest common ancestor
        return root;
    }
};