
// using recursion, with time complexity of O(W*N);
// this is kind of a brute force approach

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

// time complexity is O(N)
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

// we traverse from root node until we find the horizontal distance is equal to curr_line distance
//time complexity of this function is O(N)
void printVerticalLine(Node *curr_node, int line_no, int hd)
{
    if (curr_node == NULL)
        return;

    if (hd == line_no)
    {
        cout << curr_node->data << " ";
    }
    printVerticalLine(curr_node->left, line_no, hd - 1);
    printVerticalLine(curr_node->right, line_no, hd + 1);
}

// time complexity of this function if O(W*N) width of Tree * Number of tree nodes
void verticalOrder(Node *root)
{
    // find the min and max distance from the root node
    int min = 0, max = 0;
    findMinMax(root, &min, &max, 0);
    // now iterate from min to max and print each vertical level
    for (int i = min; i <= max; i++)
    {
        printVerticalLine(root, i, 0);
    }
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
