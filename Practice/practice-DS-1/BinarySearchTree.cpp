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

BTNode *takeInputLevelWise()
{
    int rootData;
    cin >> rootData;
    BTNode *root = new BTNode(rootData);
    queue<BTNode *> q;
    q.push(root);
    while (!q.empty())
    {
        BTNode *current = q.front();
        q.pop();
        cout << "Enter left of " << current->data << endl;
        int value;
        cin >> value;
        if (value != -1)
        {
            BTNode *leftChild = new BTNode(value);
            current->left = leftChild;
            q.push(leftChild);
        }
        cout << "Enter right of " << current->data << endl;
        cin >> value;
        if (value != -1)
        {
            BTNode *rightChild = new BTNode(value);
            current->right = rightChild;
            q.push(rightChild);
        }
    }

    return root;
}

void printTreeLevelWise(BTNode *root)
{
    if (root == NULL)
    {
        return;
    }

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

BTNode *searchBST(BTNode *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == value)
    {
        return root;
    }
    // value will be present on the right side of the tree
    if (value > root->data)
    {
        return searchBST(root->right, value);
    }
    else
    {
        return searchBST(root->left, value);
    }
}

BTNode *searchBST2(BTNode *root, int val)
{
    while (root != NULL)
    {
        if (root->data == val)
            return root;

        if (val > root->data)
            root = root->right;
        if (val < root->data)
            root = root->left;
    }
    return NULL;
}

// minimum value in BST in is the left most value
int minValue(BTNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return root->data;

    return minValue(root->left);
}

// max value in BST is the right most value
int maxValue(BTNode *root)
{
    if (root->left == NULL && root->right == NULL)
        return root->data;

    return maxValue(root->right);
}

int rangeSumBST(BTNode *root, int L, int R)
{
    if (root == NULL)
    {
        return 0;
    }

    int sum = 0;
    if (L <= root->data && root->data <= R)
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
        sum = sum + rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }

    return sum;
}

// if the in-order traversal of the BST is sorted then it is valid

bool isValidBST(BTNode *root, long long minV = -10000000000, long long maxV = 10000000000)
{
    if (root == NULL)
        return true;

    bool left = isValidBST(root->left, minV, root->data);
    bool right = isValidBST(root->right, root->data, maxV);

    if (left && right && root->data > minV && root->data < maxV)
        return true;

    return false;
}

BTNode *sortedArrToBST(vector<int> &arr, int s, int e)
{
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    BTNode *root = new BTNode(arr[mid]);

    root->left = sortedArrToBST(arr, s, mid - 1);
    root->right = sortedArrToBST(arr, mid + 1, e);

    return root;
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    BTNode *root = takeInputLevelWise();
    printTreeLevelWise(root);

    BTNode *val = searchBST2(root, 3);
    if (val)
    {
        cout << "Searched value is " << val->data << endl;
    }
    else
    {
        cout << "value not found " << endl;
    }

    cout << "Min value of the binary search tree is " << minValue(root) << endl;
    cout << "Max value of the binary search tree is " << maxValue(root) << endl;

    cout << "Range sum of BST is " << rangeSumBST(root, 1, 7) << endl;

    cout << "is valid BST " << isValidBST(root) << endl;

    vector<int> sortedArr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    BTNode *tree1 = sortedArrToBST(sortedArr, 0, sortedArr.size() - 1);

    cout << "BST From sorted Array " << endl;
    printTreeLevelWise(tree1);

    return 0;
}

/* 
input:

4
2 7
1 3 -1 -1
-1 -1 -1 -1

*/