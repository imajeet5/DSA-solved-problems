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

void preOrderTraversal(BTNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(BTNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int heightOfTree(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return max(heightOfTree(root->left), heightOfTree(root->right)) + 1;
}

bool isSymmetricHelper(BTNode<int> *leftTree, BTNode<int> *rightTree)
{
    if (leftTree == NULL && rightTree != NULL)
    {
        return false;
    }
    if (leftTree != NULL && rightTree == NULL)
    {
        return false;
    }

    if (leftTree == NULL && rightTree == NULL)
    {
        return true;
    }
    if (leftTree->data != rightTree->data)
    {
        return false;
    }

    // left side of the leftTree should be symmetric to the right side of the rightTree
    return isSymmetricHelper(leftTree->left, rightTree->right) && isSymmetricHelper(leftTree->right, rightTree->left);
}

bool isSymmetric(BTNode<int> *root)
{
    if (root == NULL)
    {
        return true;
    }

    // divide the tree into two parts and see if they are symmetric

    return isSymmetricHelper(root->left, root->right);
}

bool nodePresent(BTNode<int> *root, int value)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == value)
    {
        return true;
    }

    return nodePresent(root->left, value) || nodePresent(root->right, value);
}

int getMinValue(BTNode<int> *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    int leftMin = getMinValue(root->left);
    int rightMin = getMinValue(root->right);

    return min(root->data, min(leftMin, rightMin));
}

void getMinValue2(BTNode<int> *root, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    // initially min value will be root->data
    ans = min(ans, root->data);
    // this will update the min value by traversing through the left sub tree
    getMinValue2(root->left, ans);
    // this will update the min value by traversing through the right sub tree
    getMinValue2(root->right, ans);
}

int getNumberOfLeafNodes(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return getNumberOfLeafNodes(root->left) + getNumberOfLeafNodes(root->right);
}

void getNumberOfLeafNodes2(BTNode<int> *root, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->left == NULL && root->right == NULL)
    {
        ans++;
        return;
    }

    getNumberOfLeafNodes2(root->left, ans);
    getNumberOfLeafNodes2(root->right, ans);
}

BTNode<int> *buildTreeHelper(vector<int> &inorder, vector<int> &preorder, int inS, int inE, int preS, int preE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = preorder[preS];
    int rootIndex = -1;
    for (int i = inS; i <= inE; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPreS = preS + 1;
    int leftPreE = leftPreS + leftInE - leftInS;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPreS = leftPreE + 1;
    int rightPreE = preE;

    BTNode<int> *root = new BTNode<int>(rootData);

    root->left = buildTreeHelper(inorder, preorder, leftInS, leftInE, leftPreS, leftPreE);
    root->right = buildTreeHelper(inorder, preorder, rightInS, rightInE, rightPreS, rightPreE);

    return root;
}

BTNode<int> *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int n = inorder.size();

    return buildTreeHelper(inorder, preorder, 0, n - 1, 0, n - 1);
}

// this is my method, that I have implemented for building tree using preorder and inorder traversal
BTNode<int> *buildTree2(vector<int> preorder, vector<int> inorder)
{
    if (preorder.size() == 0)
    {
        return NULL;
    }

    int rootData = preorder[0];

    vector<int> inOrderLeft;
    int i;
    for (i = 0; i < inorder.size(); i++)
    {
        if (inorder[i] == rootData)
        {
            break;
        }
        inOrderLeft.push_back(inorder.at(i));
    }
    i++;
    vector<int> inOrderRight;
    while (i < inorder.size())
    {
        inOrderRight.push_back(inorder.at(i));
        i++;
    }

    vector<int> preOrderLeft;
    vector<int> preOrderRight;

    for (int j = 1; j < preorder.size(); j++)
    {
        if (j < inOrderLeft.size() + 1)
        {
            preOrderLeft.push_back(preorder.at(j));
        }
        else
        {
            preOrderRight.push_back(preorder.at(j));
        }
    }

    BTNode<int> *root = new BTNode<int>(rootData);
    root->left = buildTree2(preOrderLeft, inOrderLeft);
    root->right = buildTree2(preOrderRight, inOrderRight);
    return root;
}

BTNode<int> *buildTree3Helper(vector<int> &inorder, vector<int> &postorder, int inS, int inE, int postS, int postE)
{
    if (inS > inE)
    {
        return NULL;
    }

    int rootData = postorder[postE];
    int rootIndex = -1;

    for (int i = 0; i <= inE; i++)
    {
        if (inorder[i] == rootData)
        {
            rootIndex = i;
            break;
        }
    }

    int leftInS = inS;
    int leftInE = rootIndex - 1;
    int leftPostS = postS;
    int leftPostE = leftPostS + leftInE - leftInS;

    int rightInS = rootIndex + 1;
    int rightInE = inE;
    int rightPostS = leftPostE + 1;
    int rightPostE = postE - 1;

    BTNode<int> *root = new BTNode<int>(rootData);

    root->left = buildTree3Helper(inorder, postorder, leftInS, leftInE, leftPostS, leftPostE);
    root->right = buildTree3Helper(inorder, postorder, rightInS, rightInS, rightPostS, rightPostE);

    return root;
}

// building tree using postOrder and Inorder Traversal
BTNode<int> *buildTree3(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();

    return buildTree3Helper(inorder, postorder, 0, n - 1, 0, n - 1);
}

// here the time complexity is O(N*H) or O(N2) as each node is visited first for height then again for diameter

int diameterOfTree(BTNode<int> *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int option1 = heightOfTree(root->left) + heightOfTree(root->right);
    int option2 = diameterOfTree(root->left);
    int option3 = diameterOfTree(root->right);

    return max(option1, max(option2, option3));
}

// in this approach instead of calculating height and diameter severalty, we are going to calculate them combine
// time complexity has been reduced to O(1) as now it is visiting, every Node only once

pair<int, int> heightDiameter(BTNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);

    int leftheight = leftAns.first;
    int leftDiameter = leftAns.second;

    int rightheight = rightAns.first;
    int rightDiameter = rightAns.second;

    int height = 1 + max(leftheight, rightheight);

    int diameter = max(leftheight + rightheight, max(leftDiameter, rightDiameter));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;

    return p;
}

int diameterOfTreeOptimized(BTNode<int> *root)
{

    pair<int, int> p = heightDiameter(root);

    return p.second;
}

bool getPath(BTNode<int> *root, int val, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }

    ans.push_back(root->data);

    if (root->data == val)
    {
        return true;
    }

    bool isPresentLeft = getPath(root->left, val, ans);
    if (isPresentLeft)
    {
        return true;
    }
    bool isPresentRight = getPath(root->right, val, ans);
    if (isPresentRight)
    {
        return true;
    }

    ans.pop_back();

    return false;
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

    preOrderTraversal(root);
    cout << endl;
    inorderTraversal(root);

    cout << endl;

    cout << "Number of nodes " << countNodes(root) << endl;

    cout << "Height of the tree is " << heightOfTree(root) << endl;

    cout << "is tree symmetric " << isSymmetric(root) << endl;

    cout << "is node present " << nodePresent(root, 8) << endl;

    cout << "Minimum value of a node is " << getMinValue(root) << endl;
    int minVal = INT_MAX;
    getMinValue2(root, minVal);

    cout << "Min value other way " << minVal << endl;

    cout << "Number of leaf nodes are " << getNumberOfLeafNodes(root) << endl;

    cout << "diameter of the tree is " << diameterOfTree(root) << endl;

    vector<int> preorder{1, 2, 4, 3, 5, 7, 8, 6};
    vector<int> inorder{4, 2, 1, 7, 5, 8, 3, 6};

    BTNode<int> *tree1 = buildTree(preorder, inorder);
    BTNode<int> *tree2 = buildTree2(preorder, inorder);

    printTreeLevelWise(tree1);
    printTreeLevelWise(tree2);

    vector<int> path;

    if (getPath(root, 5, path))
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path.at(i) << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Value is not present" << endl;
    }

    delete root;

    return 0;
}