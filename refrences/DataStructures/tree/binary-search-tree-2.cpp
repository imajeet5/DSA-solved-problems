

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
    BTNode<int> *root;

    void printTree(BTNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << ": ";

        if (root->left != NULL)
        {

            cout << "L " << root->left->data;
        }

        if (root->right != NULL)
        {
            cout << " R " << root->right->data;
        }
        cout << endl;

        printTree(root->left);
        printTree(root->right);
    }

    bool hasData(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }

        if (node->data > data)
        {
            return hasData(node->left, data);
        }
        else
        {
            return hasData(node->right, data);
        }
    }

    BTNode<int> *insertData(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BTNode<int> *n = new BTNode<int>(data);
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

public:
    BST()
    {
        root = NULL;
    }

    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
    }

    void insertData(int data)
    {
        root = insertData(root, data);
    }

    bool hasData(int data)
    {
        return hasData(root, data);
    }

    void print()
    {
        printTree(root);
    }
};

int main(int argc, char const *argv[])
{
    BST b;
    b.insertData(10);
    b.insertData(5);
    b.insertData(20);
    b.insertData(7);
    b.insertData(3);
    b.insertData(15);

    b.print();

    cout << "has data " << b.hasData(15) << endl;
    return 0;
}