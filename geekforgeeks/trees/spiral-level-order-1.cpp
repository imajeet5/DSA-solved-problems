// using recursion

// C++ program for recursive level
// order traversal in spiral form
#include <bits/stdc++.h>
using namespace std;

// A binary tree node has data,
// pointer to left child and a
// pointer to right child
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;

    return (newnode);
}

int heightOfTree(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    // 1. get the height of the left sub Tree
    // 2. get the height of the right sub Tree
    // 3. get the max of the height of the right and left subtree and add 1 to it
    int leftTreeHeight = heightOfTree(node->left);
    int rightTreeHeight = heightOfTree(node->right);
    return max(leftTreeHeight, rightTreeHeight) + 1;
}

void printLevelOfTree(struct node *node, int lvl, bool isLeft)
{
    if (node == NULL)
    {
        return;
    }
    if (lvl == 0)
    {
        cout << node->data << " ";
        return;
    }

    if (isLeft)
    {
        printLevelOfTree(node->left, lvl - 1, isLeft);
        printLevelOfTree(node->right, lvl - 1, isLeft);
    }
    else
    {
        printLevelOfTree(node->right, lvl - 1, isLeft);
        printLevelOfTree(node->left, lvl - 1, isLeft);
    }
}

void printSpiral(struct node *node)
{
    if (node == NULL)
    {
        return;
    }

    int n = heightOfTree(node);

    bool isLeft = false;
    for (int i = 0; i <= n; i++)
    {
        printLevelOfTree(node, i, isLeft);

        isLeft = !isLeft;
    }
}

int main()
{
    struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(7);
    root->left->right = newNode(6);
    root->right->left = newNode(5);
    root->right->right = newNode(4);
    printf("Spiral Order traversal of "
           "binary tree is \n");

    printSpiral(root);

    return 0;
}