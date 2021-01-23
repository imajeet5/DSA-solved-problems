// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

Node *LCA(Node *root, int l, int h);

int main()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        int l, h;
        getline(cin, s);
        scanf("%d ", &l);
        scanf("%d ", &h);
        Node *root = buildTree(s);
        cout << LCA(root, l, h)->data << endl;
    }
    return 1;
} // } Driver Code Ends

/*The structure of a BST Node is as follows:

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Returns the LCA of the nodes with values n1 and n2
// in the BST rooted at 'root'
Node *LCA(Node *root, int n1, int n2)
{

    // case 1: not a base case if root == NULL
    if (root == NULL)
    {
        return NULL;
    }

    // case 2: root->data is equal to the number, then we have found the number and we return that node
    // act as base case

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    // if node is not found we search it DFS
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    // if for the current node number are present in left and the right subtree
    // then current node is the LCA
    if (left && right)
    {
        return root;
    }
    // here we assume that given number are present in the Binary Tree
    // no here one of either right or left is null
    // if left is not null mean right is null, then
    return left != NULL ? left : right;
}