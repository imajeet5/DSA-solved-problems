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

class BST
{
private:
    BTNode *root;

    BTNode *insertData(BTNode *node, int data)
    {
        if (node == NULL)
        {
            BTNode *n = new BTNode(data);
            return n;
        }

        if (data < node->data)
        {
            node->left = insertData(node->left, data);
        }
        else
        {
            node->right = insertData(node->right, data);
        }

        return node;
    }
    void print(BTNode *node)
    {
        if (node == NULL)
        {
            return;
        }

        cout << node->data << " ";

        if (node->left)
            cout << "L " << node->left->data;
        if (node->right)
            cout << " R " << node->right->data;
        cout << endl;

        print(node->left);
        print(node->right);
    }

    bool hasData(BTNode *node, int data)
    {
        if (node == NULL)
            return false;

        if (node->data == data)
            return true;

        if (node->data > data)
            return hasData(node->left, data);
        if (node->data < data)
            return hasData(node->right, data);
    }

    BTNode *deleteData(BTNode *node, int data)
    {
        if (node == NULL)
            return NULL;
        if (node->data == data)
        {
            // if both right and left of the node is null then we delete that node
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->left == NULL)
            {
                BTNode *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else if (node->right == NULL)
            {
                BTNode *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else
            {
                // if both right and the left side of the tree is present
                //we will replace the current node data with the lowest value on the right side and delete that lowest node
                //1. find the minimum node at the right side of the tree
                BTNode *minNode = node->right;
                while (minNode->left)
                    minNode = minNode->left;

                int minData = minNode->data;
                // 2. Now replace current node data with the right side minNode value
                node->data = minData;
                //3. Delete this minData node from the right side of the tree and replace the right with the updated node
                node->right = deleteData(node->right, minData);
            }
        }
        else if (data < node->data)
        {
            // update the left side node and delete the value from the left side tree
            node->left = deleteData(node->left, data);
        }
        else
        {
            node->right = deleteData(node->right, data);
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    void insertData(int data)
    {
        root = insertData(root, data);
    }
    void print()
    {
        print(root);
    }
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void deleteData(int data)
    {
        root = deleteData(root, data);
    }
};

int main(int argc, char const *argv[])
{
    BST tree;
    tree.insertData(10);
    tree.insertData(5);
    tree.insertData(15);
    tree.insertData(6);
    tree.insertData(2);
    tree.insertData(8);
    tree.print();
    tree.deleteData(5);
    tree.print();
    // cout << tree.hasData(123) << endl;
    return 0;
}