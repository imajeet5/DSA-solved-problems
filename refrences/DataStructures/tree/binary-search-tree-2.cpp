

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

class Pair
{
public:
    BTNode<int> *head;
    BTNode<int> *tail;
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

    BTNode<int> *deleteData(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return NULL;
        }

        if (data > node->data)
        {
            node->right = deleteData(node->right, data);
        }
        else if (data < node->data)
        {
            node->left = deleteData(node->left, data);
        }
        else
        {
            // when node->data == data

            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->right == NULL)
            {
                BTNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if (node->left == NULL)
            {
                BTNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else
            {
                BTNode<int> *minNode = node->right;
                // get the minimum Node at the right side of the tree
                // minimum node is present at the left most side of the right hand side tree
                while (minNode->left)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                // replace the current node with the update value on the right side
                node->data = rightMin;
                // update the right side of the node with the updated node from the deleteData
                node->right = deleteData(node->right, rightMin);
            }
        }
    };

    Pair convertToList(BTNode<int> *node)
    {
        if (node == NULL)
        {
            Pair p;
            p.head = NULL;
            p.tail = NULL;
            return p;
        }
        if (node->left == NULL && node->right == NULL)
        {
            Pair p;
            p.head = node;
            p.tail = node;
            return p;
        }
        else if (node->left != NULL && node->right == NULL)
        {
            // for the case where right part is null and the left part of the tree is not null
            Pair leftLL = convertToList(node->left);
            leftLL.tail->right = node;
            Pair p;
            p.head = leftLL.head;
            p.tail = node;
            return p;
        }
        else if (node->left == NULL && node->right != NULL)
        {
            Pair rightLL = convertToList(node->right);
            node->right = rightLL.head;
            Pair p;
            p.head = node;
            p.tail = rightLL.tail;
            return p;
        }
        else
        {
            Pair leftLL = convertToList(node->left);
            Pair rightLL = convertToList(node->right);
            leftLL.tail->right = node;
            node->right = rightLL.head;
            Pair p;
            p.head = leftLL.head;
            p.tail = rightLL.tail;
            return p;
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

    void deleteData(int data)
    {
        root = deleteData(root, data);
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
    BTNode<int> *convertToList()
    {
        Pair p = convertToList(root);
        BTNode<int> *temp = p.head;
        while (temp != NULL)
        {
            temp->left = NULL;
            temp = temp->right;
        }

        return p.head;
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

    // cout << "has data " << b.hasData(15) << endl;

    // cout << "After deleting " << endl;

    // b.deleteData(10);
    // b.print();
    // cout << "After deleting " << endl;
    // b.deleteData(5);
    // b.print();
    // cout << "After deleting " << endl;
    // b.deleteData(50);
    // b.print();

    BTNode<int> *head = b.convertToList();
    BTNode<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->right;
    }
    cout << endl;
    b.print();

    return 0;
}