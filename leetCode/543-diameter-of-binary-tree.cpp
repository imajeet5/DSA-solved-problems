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
    int heightOfTree(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }

        int option1 = heightOfTree(root->left) + heightOfTree(root->right);
        int option2 = diameterOfBinaryTree(root->left);
        int option3 = diameterOfBinaryTree(root->right);

        return max(option1, max(option2, option3));
    }
};