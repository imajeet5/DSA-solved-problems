#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;

    BTNode(T data)
    {
        this->data = data;
        left = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};

void printRecursively(BTNode<int> *root)
{

    // Base case
    if (root == NULL)
    {
        return;
    }

    cout << root->data << ": ";

    if (root->left)
        cout << "L " << root->left->data;
    if (root->right)
        cout << " R " << root->right->data;
    cout << endl;

    // print the left part
    printRecursively(root->left);
    printRecursively(root->right);
}

BTNode<int> *takeInputRecursive()
{
    int data;

    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    BTNode<int> *root = new BTNode<int>(data);
    cout << "Enter left of " << data << endl;
    root->left = takeInputRecursive();
    cout << "Enter right of " << data << endl;
    root->right = takeInputRecursive();

    return root;
}

BTNode<int> *takeInputLevelWise()
{
    int data;
    cin >> data;
    BTNode<int> *root = new BTNode<int>(data);
    queue<BTNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();

        cout << "Enter L for " << f->data << endl;
        cin >> data;
        if (data != -1)
        {
            BTNode<int> *leftChild = new BTNode<int>(data);
            q.push(leftChild);
            f->left = leftChild;
        }

        cout << "Enter R for " << f->data << endl;
        cin >> data;
        if (data != -1)
        {
            BTNode<int> *rightChild = new BTNode<int>(data);
            q.push(rightChild);
            f->right = rightChild;
        }
    }

    return root;
}

void printTreeLevelWise(BTNode<int> *root)
{
    queue<BTNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();
        cout << f->data << ": ";

        if (f->left)
        {
            cout << "L " << f->left->data;
            q.push(f->left);
        }
        if (f->right)
        {
            cout << " R " << f->right->data;
            q.push(f->right);
        }
        cout << endl;
    }
}

void levelOrder(BTNode<int> *root)
{
    queue<BTNode<int> *> q;

    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        BTNode<int> *f = q.front();
        q.pop();
        // either f can be NULL or a value

        if (f == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << f->data;

            if (f->left)
                q.push(f->left);

            if (f->right)
                q.push(f->right);
        }
    }
}

int countNodes(BTNode<int> *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorderTraversal(BTNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    // BTNode<int> *root = new BTNode<int>(1);
    // BTNode<int> *n1 = new BTNode<int>(2);
    // BTNode<int> *n2 = new BTNode<int>(3);

    // root->left = n1;
    // root->right = n2;

    BTNode<int> *root = takeInputLevelWise();

    inorderTraversal(root);

    cout << "Number of nodes " << countNodes(root) << endl;

    delete root;

    return 0;
}