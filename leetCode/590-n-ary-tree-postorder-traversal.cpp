#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    void postOrderHelper(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }
        for (auto child : root->children)
        {
            postOrderHelper(child, ans);
        }
        // we will do the backtracking in the post order traversal
        ans.push_back(root->val);
    }

    vector<int> postOrderHelper2(Node *root, vector<int> ans)
    {
        if (root == NULL)
        {
            return ans;
        }

        stack<Node *> s;
        stack<int> po;
        s.push(root);
        while (!s.empty())
        {
            Node *curr = s.top();
            s.pop();
            po.push(curr->val);
            for (int i = 0; i < curr->children.size(); i++)
            {
                s.push(curr->children[i]);
            }
        }

        while (!po.empty())
        {

            ans.push_back(po.top());
            po.pop();
        }
        return ans;
    }

    vector<int> preorder(Node *root)
    {
        vector<int> ans;
        postOrderHelper(root, ans);
        return ans;
    }
};