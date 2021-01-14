#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    Node *insert(Node *root, int data)
    {
        if (root == NULL)
        {
            return new Node(data);
        }
        else
        {
            Node *cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }

            return root;
        }
    }

    /*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
    map<Node *, int> dist;

    void travel(Node *root, int n)
    {
        if (root->left != NULL)
        {
            dist[root->left] = n - 1;
            travel(root->left, n - 1);
        }
        if (root->right != NULL)
        {
            dist[root->right] = n + 1;
            travel(root->right, n + 1);
        }
        return;
    }

    void topView(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        dist[root] = 0;
        travel(root, 0);
        map<int, int> view;
        queue<Node *> q;
        view[0] = root->data;
        q.push(root);
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left != NULL)
            {
                int k = dist[curr->left];
                // we will check if we have seen this value before or not
                // if we don't have then we will update the data
                // if we want bottom view of the tree we will delete this if condition
                if (view.count(k) == 0)
                    view[k] = curr->left->data;
                q.push(curr->left);
            }
            if (curr->right != NULL)
            {
                int k = dist[curr->right];
                if (view.count(k) == 0)
                    view[k] = curr->right->data;
                q.push(curr->right);
            }
        }

        for (auto i : view)
        {
            cout << i.second << " ";
        }
        return;
    }

}; //End of Solution

int main()
{

    Solution myTree;
    Node *root = NULL;

    int t;
    int data;

    std::cin >> t;

    while (t-- > 0)
    {
        std::cin >> data;
        root = myTree.insert(root, data);
    }

    myTree.topView(root);
    return 0;
}
