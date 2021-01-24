// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

bool isIdentical(Node *a, Node *b);

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

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string str, str1;
        getline(cin, str);
        Node *rootA = buildTree(str);
        getline(cin, str1);
        Node *rootB = buildTree(str1);
        if (isIdentical(rootA, rootB))
        {
            cout << "Yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
} // } Driver Code Ends

/* A binary tree node


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

// NOT WORKING

bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }
    // if above condition is true mean either both or one of them is not null
    if (r1 == NULL || r2 == NULL)
    {
        return false;
    }

    if (r1->data == r2->data)
    {
        return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
    }
    
    // r1->data != r2->data then return false
    return false;
}

bool isIdentical_xx(Node *r1, Node *r2)
{
    // we can do level order traversal of both the tree and check if they are equal
    if (r1 == NULL && r2 == NULL)
    {
        return true;
    }

    if ((r1 == NULL && r2 != NULL) || (r1 != NULL && r2 == NULL))
    {
        return false;
    }

    queue<Node *> q1;
    queue<Node *> q2;
    q1.push(r1);
    q2.push(r2);

    while (!q1.empty() && !q2.empty())
    {

        int n1 = q1.size();
        int n2 = q2.size();

        if (n1 != n2)
        {
            return false;
        }

        for (int i = 1; i <= n1; i++)
        {
            Node *f1 = q1.front();
            q1.pop();
            Node *f2 = q2.front();
            q2.pop();

            if (f1->data != f2->data)
            {
                return false;
            }

            if (f1->left)
                q1.push(f1->left);
            if (f1->right)
                q1.push(f1->right);
            if (f2->left)
                q2.push(f2->left);
            if (f2->right)
                q2.push(f2->right);
        }
    }

    if (q1.empty() && q2.empty())
    {
        return true;
    }
    return false;
}