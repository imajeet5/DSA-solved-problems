
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
    int check(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        // we will get the left height
        int lh = check(root->left);
        int rh = check(root->right);

        if (lh == -1 || rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;

        return max(lh, rh) + 1;
    }

    bool isBalanced(TreeNode *root)
    {

        return check(root) == -1 ? false : true;
    }
};