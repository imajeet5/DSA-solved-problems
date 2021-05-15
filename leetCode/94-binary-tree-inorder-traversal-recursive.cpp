
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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        stack<TreeNode *> s;
        TreeNode *curr = root;
        while (curr != NULL || !s.empty())
        {
            while (curr == NULL)
            {
                s.push(curr);
                curr = curr->left;
            }
            // if current is null we will pop from the stack and start going to the right side
            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }

        return ans;
    }
};