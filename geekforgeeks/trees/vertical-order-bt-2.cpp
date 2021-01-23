// C++ program for printing vertical order of a given binary tree
#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Structure for a binary tree node
struct Node
{
    int key;
    Node *left, *right;
};

// A utility function to create a new node
struct Node *newNode(int key)
{
    struct Node *node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return node;
}

void traverseDFS(Node *root, int x, map<int, vector<int>> &m)
{
    // base case
    if (root == NULL)
    {
        return;
    }
    m[x].push_back(root->key);

    traverseDFS(root->left, x - 1, m);
    traverseDFS(root->right, x + 1, m);
}

void printVerticalOrder(Node *root)
{
    // create a ordered map with key as hd and value as vector of data present at the vertical distance
    map<int, vector<int>> m;
    int x = 0;
    traverseDFS(root, x, m);

    for (auto pair : m)
    {
        for (int i = 0; i < pair.second.size(); i++)
        {
            cout << pair.second[i] << " ";
        }
        cout << endl;
    }
}

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
    cout << "Vertical order traversal is n" << endl;
    printVerticalOrder(root);
    return 0;
}