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
        // we will do no by using bfs
        if (x == root->val || y == root->val)
        {
            return;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            bool isXexist = false;
            bool isYexist = false;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *curr = q.front();
                q.pop();
                // check if the elements exist on the current level
                if (curr->val == x)
                    isXexist = true;
                if (curr->val == y)
                    isYexist = true;
                // now check if there exist a node on the current level
                // who is the parent of X and Y
                if (curr->left && curr->right)
                {
                    if ((curr->left->val == x && curr->right->val == y) || (curr->left->val == y && curr->right->val == x))
                    { // if there exist a node who is parent of both the node the immediatly return false
                        return false;
                    }
                }
                if (curr->left)
                {
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    q.push(curr->right);
                }
            }

            if (isXexist && isYexist)
            {
                return true;
            }
        }

        return false;
    }
};