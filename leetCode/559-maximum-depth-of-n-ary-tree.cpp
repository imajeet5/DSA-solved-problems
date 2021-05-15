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
    int maxDepthBFS(Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int depth = 0;

        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            // we will iterate through the current level elements that are pushed in the array
            for (int i = 0; i < n; i++)
            {
                // we will push children of all the element of the current level in the array
                Node *curr = q.front();
                q.pop();
                for (auto child : curr->children)
                {
                    if (child)
                        q.push(child);
                }
            }

            depth++;
        }

        return depth;
    }

    int maxDepthDFS(Node *root)
    {
        if (root == NULL)
            return 0;
        int depth = 0;
        for (auto child : root->children)
        {
            depth = max(depth, maxDepthDFS(child));
        }
        return 1 + depth;
    }
};