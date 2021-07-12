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
    string tree2str(TreeNode *root)
    {
        if (root == NULL)
            return "";
        if (root->left == NULL && root->right == NULL)
            return to_string(root->val);
        string leftString = tree2str(root->left);
        string rightString = tree2str(root->right);
        if (rightString == "")
        {
            return to_string(root->val) + "(" + leftString + ")";
        }
        else
        {
            return to_string(root->val) + "(" + leftString + ")" + "(" + rightString + ")";
        }
    }
};