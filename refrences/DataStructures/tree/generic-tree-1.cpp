#include <bits/stdc++.h>

using namespace std;

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
};

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

int main(int argc, char const *argv[])
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *n1 = new TreeNode<int>(2);
    // TreeNode<int> *n2 = new TreeNode<int>(3);

    // root->children.push_back(n1);
    // root->children.push_back(n2);

    // printTree(root);

    TreeNode<int> *root = takeInputLevelWise();

    printTree(root);

    return 0;
}