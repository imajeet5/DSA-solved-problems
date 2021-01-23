/***
 * Print Using vertical order:
 * If the two nodes are at same x then print according to level order
 * */

#include <bits/stdc++.h>

using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// A utility function to create a new node
Node *newNode(int key)
{
    Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

// The main function to print vertical oder of a
// binary tree with given root
void printVerticalOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    map<int, vector<int>> dist_map;
    queue<pair<Node *, int>> q;

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        Node *curr = p.first;
        int hd = p.second;
        dist_map[p.second].push_back(curr->key);
        if (curr->left)
        {
            q.push(make_pair(curr->left, hd - 1));
        }
        if (curr->right)
        {
            q.push(make_pair(curr->right, hd + 1));
        }
    }

    for (auto p : dist_map)
    {
        for (int i = 0; i < p.second.size(); i++)
        {
            cout << p.second[i] << " ";
        }
        cout << endl;
    }
}

// Driver program to test above functions
int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    root->right->right->left = newNode(10);
    root->right->right->left->right = newNode(11);
    root->right->right->left->right->right = newNode(12);
    cout << "Vertical order traversal is \n";
    printVerticalOrder(root);
    return 0;
}