// this will work only for binary search tree not for binary tree
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
};

// for a node to be the LCA in a BST n1 and n2 must be lie on the right and left side of the tree
// so we check if the both n1 and n2 are small then we move left and vice-versa for right
//
struct node *lca(struct node *root, int n1, int n2)
{
    while (root != NULL)
    {
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
        if (root->data > n1 && root->data > n2)
            root = root->left;

        // If both n1 and n2 are greater than root,
        // then LCA lies in right
        else if (root->data < n1 && root->data < n2)
            root = root->right;

        else
        // either root->data is == n1 or n2 , and one of the other is smaller
        // or one of the node is smaller and other is greater and current node is LCA
            break;
    }
    return root;
}

/* Helper function that allocates  
a new node with the given data.*/
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = Node->right = NULL;
    return (Node);
}

/* Driver code*/
int main()
{
    // Let us construct the BST
    // shown in the above figure
    node *root = newNode(20);
    root->left = newNode(8);
    root->right = newNode(22);
    root->left->left = newNode(4);
    root->left->right = newNode(12);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(14);

    int n1 = 10, n2 = 14;
    node *t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    cout << "LCA of " << n1 << " and " << n2 << " is " << t->data << endl;
    return 0;
}
