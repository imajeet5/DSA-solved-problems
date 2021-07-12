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
    pair<int, int> heightDiameterOfTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return {0, 0};
        }

        pair<int, int> lhd = heightDiameterOfTree(root->left);
        pair<int, int> rhd = heightDiameterOfTree(root->right);

        int lh = lhd.first;
        int ld = lhd.second;

        int rh = rhd.first;
        int rd = rhd.second;

        int height = 1 + max(lh, rh);
        int diameter = max(lh + rh, max(ld, rd));

        return {height, diameter};
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        return heightDiameterOfTree(root).first;
    }
};