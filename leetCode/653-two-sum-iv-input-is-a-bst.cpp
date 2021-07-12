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
    bool findTarget(TreeNode *root, int k)
    {
        unordered_set<int> comp;
        return dfs(root, k, comp);
    }

    bool dfs(TreeNode *root, int target, unordered_set<int> &comp)
    {
        if (root == NULL)
        {
            return true;
        }
        // if the complement sum exist in the set, then we have found our value, then return
        if (comp.find(root->val) != comp.end())
        {
            return true;
        }
        // otherwise push the complement value in the set for future use
        comp.insert(target - root->val);

        // now traverse the left and right subtree to check the same condition
        return dfs(root->left, target, comp) || dfs(root->right, target, comp);
    }
};