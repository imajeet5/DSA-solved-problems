// driver code

#include <iostream>
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

bool isLoop(Node *head)
{
    if (!head)
        return false;

    Node *fast = head->next;
    Node *slow = head;

    while (fast != slow)
    {
        if (!fast || !fast->next)
            return false;
        fast = fast->next->next;
        slow = slow->next;
    }

    return true;
}

int length(Node *head)
{
    int ret = 0;
    while (head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}

void removeLoop(Node *head);

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

        removeLoop(head);

        if (isLoop(head) || length(head) != n)
            cout << "0\n";
        else
            cout << "1\n";
    }
    return 0;
}
// } Driver Code Ends

/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

void removeLoop(Node *head)
{
    //1. check if there exist a loop
    if (head == NULL || head->next == NULL)
        return;

    Node *S = head;
    Node *F = head;
    // prev pointer will just be before the F pointer, as we have to break the link from that location
    Node *prev = head;

    bool loopExist = false;

    while (F->next && F->next->next)
    {
        S = S->next;
        prev = F->next;
        F = F->next->next;
        if (S == F)
        {
            loopExist = true;
            break;
        }
    }

    if (!loopExist)
        return;

    S = head;
    while (S != F)
    {
        S = S->next;
        prev = prev->next;
        F = F->next;
    }

    prev->next = NULL;
}