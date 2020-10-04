#include <bits/stdc++.h>

using namespace std;

class BTNode
{
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
};

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}