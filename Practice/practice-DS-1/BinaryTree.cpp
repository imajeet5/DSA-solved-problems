#include <bits/stdc++.h>

using namespace std;

class BTNode
{
public:
    int data;
    BTNode *left;
    BTNode *right;

    BTNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};

void printTree(BTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << ": ";
    if (root->left)
    {
        cout << "L " << root->left->data;
    }
    if (root->right)
    {
        cout << " R " << root->right->data;
    }
    cout << endl;

    printTree(root->left);
    printTree(root->right);
}

BTNode *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    BTNode *root = new BTNode(rootData);
    cout << "Enter left of " << rootData << endl;
    root->left = takeInput();
    cout << "Enter right of " << rootData << endl;
    root->right = takeInput();

    return root;
}

BTNode *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    queue<BTNode *> q;
    BTNode *root = new BTNode(rootData);
    q.push(root);
    while (!q.empty())
    {
        BTNode *current = q.front();
        q.pop();
        cout << "Enter Left of " << current->data << endl;
        int value;
        cin >> value;
        if (value != -1)
        {
            BTNode *leftChild = new BTNode(value);
            q.push(leftChild);
            current->left = leftChild;
        }

        cout << "Enter Right of " << current->data << endl;
        cin >> value;
        if (value != -1)
        {
            BTNode *rightChild = new BTNode(value);
            q.push(rightChild);
            current->right = rightChild;
        }
    }
    return root;
}

void printLevelWise(BTNode *root)
{
    queue<BTNode *> q;
    q.push(root);

    while (!q.empty())
    {
        BTNode *current = q.front();
        q.pop();
        cout << current->data << ": ";
        if (current->left)
        {
            cout << "L " << current->left->data << " ";
            q.push(current->left);
        }
        if (current->right)
        {
            cout << "R " << current->right->data;
            q.push(current->right);
        }
        cout << endl;
    }
}

void levelOrderPrinting(BTNode *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<BTNode *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        BTNode *current = q.front();
        q.pop();

        if (current != NULL)
        {
            cout << current->data;
            if (current->left)
                q.push(current->left);
            if (current->right)
                q.push(current->right);
        }
        else
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
    }
}

int countNodes(BTNode *root)
{
    if (root == NULL)
        return 0;

    return countNodes(root->right) + countNodes(root->left) + 1;
}

// in in order traversal first we visit the left subtree and then the node and then right subtree
void inOrderTraversal(BTNode *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// in pre-order traversal we first visit the data then the left subtree and then right subtree.
// this is also top down approach, we first visit the data then we visit the childs
void preOrderTraversal(BTNode *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// in post order traversal we first visit the left subtree then the right subtree and finally data

void postOrderTraversal(BTNode *root)
{
    if (root == NULL)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int heightOfTree(BTNode *root)
{
    if (root == NULL)
        return 0;

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

bool isSymmetricHelper(BTNode *left, BTNode *right)
{
    if (left == NULL && right == NULL)
        return true;
    if (left != NULL && right == NULL)
        return false;
    if (left == NULL && right != NULL)
        return false;
    if (left->data != right->data)
        return false;

    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
}

bool isTreeSymmetric(BTNode *root)
{
    if (root == NULL)
    {
        return true;
    }

    // this function will compare the left side of the left subtree and right side of the right subtree
    isSymmetricHelper(root->left, root->right);
}

bool isNodePresent(BTNode *root, int value)
{
    if (root == NULL)
        return false;

    if (root->data == value)
        return true;

    bool isPresentLeft = isNodePresent(root->left, value);
    if (isPresentLeft)
        return true;
    bool isPresentRight = isNodePresent(root->right, value);
    if (isPresentRight)
        return true;
    return false;
}

int getMinValue(BTNode *root, int min_val = INT_MAX)
{
    if (root == NULL)
        return min_val;
    if (root->data < min_val)
        min_val = root->data;

    min_val = min(min_val, getMinValue(root->left, min_val));
    min_val = min(min_val, getMinValue(root->right, min_val));

    return min_val;
}

BTNode *buildTreeHelper1(vector<int> &inorder, vector<int> &preorder, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }
    int rootData = preorder[preS];
    int rootIndex = -1;
    for (int i = 0; i <= inE; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    // we got the root value, now we will again divide the tree in two halves
    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPreS = preS + 1;
    int leftPreE = leftPreS + leftInE - leftPreS;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    BTNode *root = new BTNode(rootData);

    root->left = buildTreeHelper1(inorder, preorder, leftInS, leftInE, leftPreS, leftPreE);
    root->right = buildTreeHelper1(inorder, preorder, rightInS, rightInE, rightPreS, rightPreE);

    return root;
}

BTNode *buildTreePreOrderInorder(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);

    // BTNode *root = new BTNode(1);
    // BTNode *n2 = new BTNode(3);
    // BTNode *n3 = new BTNode(4);
    // BTNode *n4 = new BTNode(5);
    // BTNode *n5 = new BTNode(6);
    // BTNode *n6 = new BTNode(7);

    // root->left = n2;
    // root->right = n3;
    // n2->left = n4;
    // n2->right = n5;
    // n3->right = n6;
    BTNode *root = takeInputLevelWise();

    cout << "Printing recursively" << endl;

    printTree(root);

    cout << "Printing level wise" << endl;

    printLevelWise(root);

    cout << "Printing level order" << endl;

    levelOrderPrinting(root);

    cout << "total number of node present " << countNodes(root) << endl;

    cout << "Inorder traversal " << endl;
    inOrderTraversal(root);
    cout << endl;

    cout << "Preorder traversal " << endl;
    preOrderTraversal(root);
    cout << endl;

    cout << "PostOrder traversal " << endl;
    postOrderTraversal(root);
    cout << endl;

    cout << "Height of the tree is " << heightOfTree(root) << endl;

    cout << "Is tree symmetric " << isTreeSymmetric(root) << endl;

    cout << "value present " << isNodePresent(root, 19) << endl;

    cout << "Minimun value is " << getMinValue(root) << endl;

    return 0;
}

/*
input:
1
2 3
5 6 -1 4
-1 -1 -1 -1 -1 8
9 -1 -1 -1





*/