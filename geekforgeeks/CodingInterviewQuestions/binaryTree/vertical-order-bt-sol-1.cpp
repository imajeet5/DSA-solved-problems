
#include <iostream>
using namespace std;

// A node of binary tree
struct Node
{
    int data;
    struct Node *left, *right;
};

// A utility function to create a new Binary Tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
};

void findMinMax(Node *curr_node, int *min, int *max, int hd)
{
    if (!curr_node)
    {
        return;
    }

    if (hd < *min)
        *min = hd;
    else if (hd > *max)
        *max = hd;

    findMinMax(curr_node->left, min, max, hd - 1);
    findMinMax(curr_node->right, min, max, hd - 1);
}

void verticalOrder(Node *root)
{
    // find the min and max distance from the root node
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
}

int main()
{
    // Create binary tree shown in above figure
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);

    cout << "Vertical order traversal is \n";
    verticalOrder(root);
