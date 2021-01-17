#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    // constructor
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

//height of Binary Tree
int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftTreeHeight = height(root->left);
    int rightTreeHeight = height(root->right);
    return max(leftTreeHeight, rightTreeHeight) + 1;
}

//level order using recursion
void printGivenLevel(Node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}

void levelOrderSameLine(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *current = q.front();
        cout << current->data << " ";
        q.pop();
        if (current->left)
            q.push(current->left);
        if (current->right)
            q.push(current->right);
    }
}
// BFS
void levelOrderNextLine(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();
        if (current == NULL)
        {
            cout << endl;
            // we will check if the q is not empty after popping
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << current->data << " ";
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
    }
}

int main(int argc, char const *argv[])
{

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->left->right = new Node(9);
    root->left->right = new Node(5);
    root->left->right->left = new Node(10);
    root->right->left = new Node(6);
    root->right->left->right = new Node(11);
    root->right->right = new Node(7);
    root->right->right->right = new Node(12);
    int heightTree = height(root);
    cout << "Height of the tree is " << heightTree << endl;
    for (int i = 1; i <= heightTree; i++)
    {
        printGivenLevel(root, i);
        cout << endl;
    }
    // printGivenLevel(root, 3);

    return 0;
}