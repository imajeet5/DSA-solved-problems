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
    bool isCousins(TreeNode *root, int x, int y)
    {
        // we will traverse throught the whole tree and store its current level and parent in the map
        // node->val : {level, parent}
        if (x == root->val || y == root->val)
        {
            return false;
        }
        unordered_map<int, pair<int, int>> mp;
        dfs(root->left, mp, root->val, 0);
        dfs(root->right, mp, root->val, 0);
        auto xD = mp[x];
        auto yD = mp[y];
        // if level is equal and parent is not equal
        if ((xD.first == yD.first) && (xD.second != yD.second))
        {
            return true;
        }
        return false;
    }

    void dfs(TreeNode *root, unordered_map<int, pair<int, int>> &mp, int parent, int level)
    {
        if (root == NULL)
        {
            return;
        }

        mp[root->val] = {level, parent};
        dfs(root->left, mp, root->val, level + 1);
        dfs(root->right, mp, root->val, level + 1);
    }
};