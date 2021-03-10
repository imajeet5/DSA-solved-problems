// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool detectLoop(Node *head);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, num;
        cin >> n;

        Node *head, *tail;
        cin >> num;
        head = tail = new Node(num);

        for (int i = 0; i < n - 1; i++)
        {
            cin >> num;
            tail->next = new Node(num);
            tail = tail->next;
        }

        int pos;
        cin >> pos;
        loopHere(head, tail, pos);

        if (detectLoop(head))
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/

bool detectLoop(Node *head)
{
    // your code here
    unordered_set<Node *> nodeAddress;
    while (head != NULL)
    {
        if (nodeAddress.find(head) != nodeAddress.end())
            return true;
        nodeAddress.insert(head);
        head = head->next;
    }
    return false;
}

bool detectLoop2(Node *head)
{
    if (head == NULL || head->next == NULL)
        return false;
    Node *F = head;
    Node *S = head;
    while (F->next != NULL && F->next->next != NULL)
    {
        F = F->next->next;
        S = S->next;
        if (F == S)
            return true;
    }

    // getting the node of the loop;
    // initialize the S pointer back to the start of the loop
    S = head;
    // move both fast and slow pointer by one
    while (S != F)
    {
        S = S->next;
        F = F->next;
    }

    cout << S->data << " is the loop starting point" << endl;

    return false;
}