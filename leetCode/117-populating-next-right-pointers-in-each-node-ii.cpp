#include <bits/stdc++.h>

using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        // take three pointer
        Node *head = NULL;
        Node *prev = NULL;
        Node *curr = root;
        while (curr)
        {

            while (curr)
            {

                if (curr->left)
                {

                    if (prev)
                    {

                        // then add the current node to prev->next
                        prev->next = curr->left;
                    }
                    else
                    {
                        // then this is the first node of this level and we will store it's position in head
                        head = curr->left;
                    }
                    // now prev will point to the curr node
                    prev = curr->left;
                }

                if (curr->right)
                {
                    if (prev)
                    {

                        prev->next = curr->right;
                    }
                    else
                    {
                        head = curr->right;
                    }

                    prev = curr->right;
                }

                // now move the current along the path that is create by prev
                curr = curr->next;
            }

            // when the path of this level is over we will move to the next level using the help of the head pointer
            curr = head;
            // reset the value of head and prev as we are moving to the next level
            head = NULL;
            prev = NULL;
        }

        return root;
    }
};

class SolutionBFS
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return root;
        auto node = root;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            int n = q.size();
            while (n)
            {
                auto curr = q.front();
                q.pop();
                if (n != 1)
                    curr->next = q.front();
                else
                    curr->next = NULL;
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
                n--;
            }
        }
        return root;
    }
};

int main(int argc, char const *argv[])
{
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}