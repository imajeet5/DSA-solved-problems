#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;
    TreeNode(int data)
    {
        this->data = data;
    }
};

void printTree(TreeNode *root)
{
    cout << root->data << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

TreeNode *takeInput()
{
    int data;
    cout << "Enter a number:" << endl;
    cin >> data;
    TreeNode *root = new TreeNode(data);
    // get number of childrens
    int n;
    cout << "Enter numbers of childrens " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        int n;
        cout << "Enter the number of childrens of " << front->data;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter " << i << " th child of " << front->data << endl;
            cin >> childData;
            TreeNode *child = new TreeNode(childData);
            q.push(child);
            front->children.push_back(child);
        }
    }
}

void printTreeLevelWise(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();

        cout << front->data << ": ";
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ", ";
            q.push(front->children[i]);
        }
        cout << endl;
    }
}

int countNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }

    return ans;
}

int heightOfTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int mx = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childHeight = heightOfTree(root->children[i]);
        if (childHeight > mx)
        {
            mx = childHeight;
        }
    }
    return mx + 1;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    TreeNode *n1 = new TreeNode(2);
    TreeNode *n2 = new TreeNode(3);

    root->children.push_back(n1);
    root->children.push_back(n2);
    int numChilds = countNodes(root);
    cout << "Number of childs are " << numChilds << endl;
    // TreeNode *root = takeInput();

    // printTree(root);
    printTreeLevelWise(root);

    return 0;
}