#include <bits/stdc++.h>

using namespace std;

// std::ifstream fin("_input.txt");

// #define cin fin

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children;
    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);
    //number of children for input node
    int num_children;
    cout << "Enter the number of children of " << rootData << endl;
    cin >> num_children;

    for (int i = 0; i < num_children; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
};

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;

    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> qu;
    qu.push(root);

    while (!qu.empty())
    {
        TreeNode<int> *f = qu.front();
        qu.pop();

        cout << "Enter number of childrens of " << f->data << endl;
        int num_childrens;
        cin >> num_childrens;

        // cout << "Enter childrens of " << f->data << endl;
        for (int i = 0; i < num_childrens; i++)
        {
            int childData;
            cout << "Enter child " << i << " of " << f->data << endl;
            cin >> childData;
            //1. create the node
            TreeNode<int> *child = new TreeNode<int>(childData);
            qu.push(child);
            f->children.push_back(child);
        }
    }

    return root;
}

void printTree(TreeNode<int> *root)
{
    // this is an edge case, it is not a base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ": ";

    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        cout << f->data << ": ";

        for (int i = 0; i < f->children.size(); i++)
        {
            q.push(f->children[i]);
            cout << f->children[i]->data << " ";
        }
        cout << endl;
    }
}

int numberOfNodes(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    int num_Nodes = 0;
    while (!q.empty())
    {
        TreeNode<int> *f = q.front();
        q.pop();
        num_Nodes++;
        for (int i = 0; i < f->children.size(); i++)
        {
            q.push(f->children[i]);
        }
    }

    return num_Nodes;
}

int numOfNodes_recursion(TreeNode<int> *root)
{
    int num_nodes = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        num_nodes += numOfNodes_recursion(root->children[i]);
    }

    return num_nodes;
}

int height(TreeNode<int> *root)
{
    // this is the edge case
    if (root == NULL)
    {
        return 0;
    }

    int mx = 0;

    for (int i = 0; i < root->children.size(); i++)
    {

        mx = max(mx, height(root->children[i]));
    }
    return mx + 1;
}

void printatdepth(TreeNode<int> *root, int depth)
{

    if (depth == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (size_t i = 0; i < root->children.size(); i++)
    {
        printatdepth(root->children[i], depth - 1);
    }
}

int totalLeafNodes(TreeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        return 1;
    }
    int leafNodes = 0;
    for (size_t i = 0; i < root->children.size(); i++)
    {
        leafNodes += totalLeafNodes(root->children[i]);
    }

    return leafNodes;
}

void preOrder(TreeNode<int> *root)
{
    cout << root->data << " ";
    for (size_t i = 0; i < root->children.size(); i++)
    {
        preOrder(root->children[i]);
    }
}

void postOrder(TreeNode<int> *root)
{

    for (int i = 0; i < root->children.size(); i++)
    {
        postOrder(root->children[i]);
    }
    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }

    delete root;
}

int main(int argc, char const *argv[])
{

    freopen("_input.txt", "r", stdin);

    // freopen("_output.txt", "w", stdout);

    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *n1 = new TreeNode<int>(2);
    // TreeNode<int> *n2 = new TreeNode<int>(3);

    // root->children.push_back(n1);
    // root->children.push_back(n2);

    // printTree(root);

    TreeNode<int> *root = takeInputLevelWise();

    cout << endl;

    printTree(root);

    cout << "Number of nodes are " << numOfNodes_recursion(root) << endl;
    cout << "Height of tree " << height(root) << endl;
    printatdepth(root, 2);
    cout << endl;

    cout << "Total leaf nodes " << totalLeafNodes(root) << endl;

    cout << "Pre order traversal" << endl;
    preOrder(root);
    cout << endl;
    cout << "Post order traversal" << endl;
    postOrder(root);
    cout << endl;

    delete root;

    return 0;
}