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
    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<int> currPath;
        vector<vector<int>> allPaths;
        dfs(root, currPath, allPaths);
        string cp;
        vector<string> ans;

        for (auto path : allPaths)
        {
            cp = to_string(path[0]);
            for (int i = 1; i < path.size(); i++)
            {
                cp += "->" + to_string(path[i]);
            }
            ans.push_back(cp);
        }

        return ans;
    }
    void dfs(TreeNode *root, vector<int> &currPath, vector<vector<int>> &allPaths)
    {
        if (root == NULL)
        {
            return;
        }
        currPath.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            allPaths.push_back(currPath);
            currPath.pop_back();
            return;
        }

        dfs(root->left, currPath, allPaths);
        dfs(root->right, currPath, allPaths);
        currPath.pop_back();
    }
};