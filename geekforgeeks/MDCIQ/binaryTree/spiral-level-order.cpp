// Solved this entire problem all by myself without any external help
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};
// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

vector<int> findSpiral(Node *root);

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
    Node *root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);

        vector<int> vec = findSpiral(root);
        for (int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends

/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

vector<int> findSpiral(Node *root)
{
    //Do a BSF or level order traversal but instead of printing store each level in array
    // we have to know where each level start and end so for that we have to use a placeholder
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<Node *> q;
    int curr_level = 0;
    q.push(root);
    q.push(NULL);
    // key: level and value: node data
    map<int, vector<int>> level_map;

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr == NULL && !q.empty())
        {
            curr_level++;
            q.push(NULL);
            continue;
        }
        if (q.empty())
        {
            break;
        }
        level_map[curr_level].push_back(curr->data);
        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }

    bool isReverse = false;

    for (auto p : level_map)
    {
        if (!isReverse)
        {
            for (int i = 0; i < p.second.size(); i++)
            {
                ans.push_back(p.second[i]);
            }
        }
        else
        {
            int lastIdx = p.second.size() - 1;
            for (int i = lastIdx; i >= 0; i--)
            {
                ans.push_back(p.second[i]);
            }
        }
        if (p.first >= 1)
            isReverse = !isReverse;
    }
}