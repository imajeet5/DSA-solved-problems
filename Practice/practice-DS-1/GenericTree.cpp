#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> childrens;
    TreeNode(int data)
    {
        this->data = data;
    }
    // delete constructor is get called before the delete operator is executed on the object
    ~TreeNode()
    {
        // here we are recursively deleting all the childrens of the node
        for (int i = 0; i < childrens.size(); i++)
        {
            delete childrens[i];
        }
    }
};

void printTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ": ";

    for (int i = 0; i < root->childrens.size(); i++)
    {
        cout << root->childrens[i]->data << ", ";
    }
    cout << endl;

    for (int i = 0; i < root->childrens.size(); i++)
    {

        printTree(root->childrens[i]);
    }
}

void printTreeLevelWise(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        cout << current->data << ": ";

        for (int i = 0; i < current->childrens.size(); i++)
        {
            cout << current->childrens[i]->data << ", ";
            q.push(current->childrens[i]);
        }

        cout << endl;
    }
};

TreeNode *takeInput()
{

    cout << "Enter the value of node" << endl;
    int data;
    cin >> data;

    TreeNode *root = new TreeNode(data);

    cout << "number of children of " << data << "?" << endl;
    int childrens;
    cin >> childrens;
    for (int i = 0; i < childrens; i++)
    {
        TreeNode *child = takeInput();
        root->childrens.push_back(child);
    }

    return root;
}

TreeNode *takeInputLevelWise()
{
    int data;
    cin >> data;
    TreeNode *root = new TreeNode(data);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        cout << "Enter number of childrens of " << current->data << endl;
        int childrens;
        cin >> childrens;
        for (int i = 0; i < childrens; i++)
        {
            cout << "Enter child-" << i << " of " << current->data << endl;
            int childData;
            cin >> childData;
            TreeNode *n = new TreeNode(childData);
            current->childrens.push_back(n);
            q.push(n);
        }
    }

    return root;
}

int numberOfNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int num_nodes = 0;

    for (int i = 0; i < root->childrens.size(); i++)
    {
        num_nodes += numberOfNodes(root->childrens[i]);
    }

    return num_nodes + 1;
}

int numberOfNodes2(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    queue<TreeNode *> q;
    q.push(root);
    int num_nodes = 0;
    while (!q.empty())
    {
        TreeNode *current = q.front();
        q.pop();
        num_nodes++;
        for (size_t i = 0; i < current->childrens.size(); i++)
        {
            q.push(current->childrens[i]);
        }
    }

    return num_nodes;
}

int heightOfTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int mx = 0;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        int childTreeHight = heightOfTree(root->childrens[i]);
        if (childTreeHight > mx)
        {
            mx = childTreeHight;
        }
    }
    return mx + 1;
}

void printatdepth(TreeNode *root, int depth)
{
    if (root == NULL)
    {
        return;
    }
    if (depth == 0)
    {
        cout << root->data << endl;
    }
    for (int i = 0; i < root->childrens.size(); i++)
    {
        printatdepth(root->childrens[i], depth - 1);
    }
}

int totalLeafNodes(TreeNode *root)
{
    if (root->childrens.size() == 0)
    {
        return 1;
    }
    int leafNodes = 0;
    for (int i = 0; i < root->childrens.size(); i++)
    {
        leafNodes += totalLeafNodes(root->childrens[i]);
    }
    return leafNodes;
}

// in preOrder traversal first we print the root then we print the childrens
// this is top down approach
void preOrder(TreeNode *root)
{
    cout << root->data << " ";
    for (int i = 0; i < root->childrens.size(); i++)
    {
        preOrder(root->childrens[i]);
    }
}

// in postOrder traversal we first print the childrens then we print the root
// this is bottom up approach
void postOrder(TreeNode *root)
{
    for (int i = 0; i < root->childrens.size(); i++)
    {
        postOrder(root->childrens[i]);
    }

    cout << root->data << " ";
}

// first we do the post order traversal to reach the end node, then we delete that node
void deleteTree(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->childrens.size(); i++)
    {
        deleteTree(root->childrens[i]);
    }

    delete root;
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    // TreeNode *root = new TreeNode(1);
    // TreeNode *n1 = new TreeNode(2);
    // TreeNode *n2 = new TreeNode(3);
    // TreeNode *n3 = new TreeNode(4);
    // TreeNode *n4 = new TreeNode(5);

    // root->childrens.push_back(n1);
    // root->childrens.push_back(n2);
    // root->childrens.push_back(n3);
    // n1->childrens.push_back(n4);

    TreeNode *root = takeInputLevelWise();

    printTreeLevelWise(root);

    cout << "Number of nodes are " << numberOfNodes2(root) << endl;
    cout << "Height of the tree is " << heightOfTree(root) << endl;
    cout << "total leaf nodes are " << totalLeafNodes(root) << endl;

    printatdepth(root, 2);

    cout << "PreOrder traversal" << endl;
    preOrder(root);
    cout << endl;

    cout << "PostOrder traversal" << endl;
    postOrder(root);
    cout << endl;

    cout << "Deleting tree " << endl;
    deleteTree(root);
    printTreeLevelWise(root);

    return 0;
}

/*
input:
1
3
2 3 4
1
5
3
6 7 8
1
10
0
1
9
0
0
0
0





*/