#include <bits/stdc++.h>

using namespace std;

template <typename T>
class BSTNode
{
public:
    T data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BSTNode()
    {
        delete left;
        delete right;
    }
};

BSTNode<int> *takeInputLevelWise()
{
    int data;
    cin >> data;
    BSTNode<int> *root = new BSTNode<int>(data);
    queue<BSTNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BSTNode<int> *f = q.front();
        q.pop();

        cout << "Enter L for " << f->data << endl;
        cin >> data;
        if (data != -1)
        {
            BSTNode<int> *leftChild = new BSTNode<int>(data);
            q.push(leftChild);
            f->left = leftChild;
        }

        cout << "Enter R for " << f->data << endl;
        cin >> data;
        if (data != -1)
        {
            BSTNode<int> *rightChild = new BSTNode<int>(data);
            q.push(rightChild);
            f->right = rightChild;
        }
    }

    return root;
}

void printTreeLevelWise(BSTNode<int> *root)
{
    queue<BSTNode<int> *> q;
    q.push(root);

    while (!q.empty())
    {
        BSTNode<int> *f = q.front();
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

BSTNode<int> *searchBST(BSTNode<int> *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }

    if (val > root->data)
    {
        return searchBST(root->right, val);
    }
    else if (val < root->data)
    {
        return searchBST(root->left, val);
    }
}

BSTNode<int> *searchBST2(BSTNode<int> *root, int val)
{

    while (root != NULL)
    {
        if (root->data == val)
        {
            return root;
        }
        else if (val > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return NULL;
}

// minimum value of the BST node is the left most extreme value
int minValueInBST(BSTNode<int> *root)
{
    if (root == NULL)
    {
        return -1;
    }

    while (root->left != NULL)
    {
        root = root->left;
    }

    return root->data;
}

// the value present at the extreme right will be the max value
int maxValueInBST(BSTNode<int> *root)
{
    if (root == NULL)
    {
        return -1;
    }
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int rangeSumBST(BSTNode<int> *root, int L, int R)
{
    if (root == NULL)
    {
        return 0;
    }

    int sum = 0;

    // if root->data is between the given range
    if (root->data >= L && root->data <= R)
    {
        sum += root->data;
    }

    if (root->data > R)
    {
        sum += rangeSumBST(root->left, L, R);
    }
    else if (root->data < L)
    {
        sum += rangeSumBST(root->right, L, R);
    }
    else
    {
        sum += rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }

    return sum;
}

bool isValidBST(BSTNode<int> *root, long long minV = -10000000000, long long maxV = 10000000000)
{
    if (root == NULL)
    {
        return true;
    }

    bool left = isValidBST(root->left, minV, root->data);
    bool right = isValidBST(root->right, root->data, maxV);

    if (left && right && root->data > minV && root->data < maxV)
    {
        return true;
    }
    return false;
}

BSTNode<int> *sortedArrToBST(vector<int> &arr, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    
    int rootData = arr.at(mid);

    BSTNode<int> *root = new BSTNode<int>(rootData);
    root->left = sortedArrToBST(arr, s, mid - 1);
    root->right = sortedArrToBST(arr, mid + 1, e);

    return root;
}

int main(int argc, char const *argv[])
{
     freopen("_input.txt", "r", stdin);

    BSTNode<int> *root = takeInputLevelWise();

    BSTNode<int> *node = searchBST(root, 7);

    cout << "value of node is " << node->data << endl;

    cout << "Min value in the tree is " << minValueInBST(root) << endl;
    cout << "Max value in the tree is " << maxValueInBST(root) << endl;

    printTreeLevelWise(root);

    vector<int> sortedArr{1, 2, 3, 4, 5, 6, 7, 8,9, 10, 11, 12};

    BSTNode<int> *tree1 = sortedArrToBST(sortedArr, 0, sortedArr.size() - 1);

    cout << "BST From sorted Array " << endl;
    printTreeLevelWise(tree1);

    return 0;
}

/*
input 1:
4
2 7
1 3 -1 -1
-1 -1 -1 -1

*/