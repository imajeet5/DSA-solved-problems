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

// using recursion
void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
};

// inorder traversal using Stack without recursion
void inOrderUsingStack(struct Node *root)
{
    stack<Node *> s;
    Node *curr = root;

    // only exit when curr is NULL and stack is empty
    while (curr != NULL || s.empty() == false)
    {
        /* Reach the left most Node of the 
           curr Node */
        while (curr != NULL)
        {
            /* place pointer to a tree node on 
               the stack before traversing 
              the node's left subtree */
            s.push(curr);
            curr = curr->left;
        }

        /* Current must be NULL at this point */
        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        /* we have visited the node and its 
           left subtree.  Now, it's right 
           subtree's turn */
        curr = curr->right;

    } /* end of while */
}

/**
 * In this method we first create a pointer on all the last right nodes to their predecessor top node and move current one left
 * this process is repeated for all the left node, with all right node pointing to their predecessors
 * When current reached the last, i.e. current->left == NULL then we print the current and move current on level up using right pointer reference that we stored earlier.
 * Now we again get to the right most node as left has been visited and print the current->data and remove the reference that we have created
 * current move to the right node and process continues. 
 * 
*/

void MorrisTraversal(struct Node *root)
{
    struct Node *current, *pre;

    if (root == NULL)
        return;

    current = root;
    while (current != NULL)
    {

        if (current->left == NULL)
        {
            printf("%d ", current->data);
            current = current->right;
        }
        else
        {

            /* Find the inorder predecessor of current */
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;

            // case if pre->right is NULL, means node has not been visited. Then we will point the right to current
            if (pre->right == NULL)
            {
                pre->right = current;
                current = current->left;
            }
            // case when pre->right is pointing to current. Means the node has been visited and we print the node
            // and break the connection.
            else
            {
                pre->right = NULL;
                printf("%d ", current->data);
                current = current->right;
            } /* End of if condition pre->right == NULL */
        }     /* End of if condition current->left == NULL*/
    }         /* End of while */
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
    MorrisTraversal(root);

    return 0;
}