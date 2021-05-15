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
    vector<double> averageOfLevels(TreeNode *root)
    {
        vector<double> ans;
        if (root == NULL)
        {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int levelSize = q.size();
            double sum = 0;
            for (int i = 0; i < levelSize; i++)
            {
                TreeNode *item = q.front();
                q.pop();
                sum += item->val;
                if (item->left)
                    q.push(item->left);
                if (item->right)
                    q.push(item->right);
            }
            double avg = (double)sum / levelSize;
            ans.push_back(avg);
        }

        return ans;
    }

    vector<double> averageOfLevels2(TreeNode *root)
    {
        vector<int> count;
        vector<int> sums;
        vector<double> result;
        averageDFS(root, 0, count, sums);
        for (int i = 0; i < sums.size(); i++)
        {
            result.push_back((double)sums[i] / count[i]);
        }
        return result;
    }

    void averageDFS(TreeNode *node, int level, vector<int> count, vector<int> sums)
    {
        if (node == NULL)
        {
            return;
        }
        // there are two cases now either levels is already visited or it is visited first time
        //1. if it is already visited
        if (level < sums.size())
        {
            sums[level] += node->val;
            count[level]++;
        }
        else
        {
            //2. if level is visited for the first time
            sums.push_back(node->val);
            count.push_back(level);
        }

        // now traverse to the left then to the right side of the tree
        averageDFS(node->left, level + 1, count, sums);
        averageDFS(node->right, level + 1, count, sums);
    }
};