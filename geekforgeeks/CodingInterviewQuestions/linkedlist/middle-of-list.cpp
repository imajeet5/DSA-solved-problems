
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}
/* Function to get the middle of the linked list*/
int getMiddle(Node *head);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        cout << getMiddle(head) << endl;
    }
    return 0;
}

int getMiddle(Node *head)
{
    Node *i = head;
    Node *j = head->next;
    while (j && j->next)
    {
        i = i->next;
        j = j->next->next;
    }
    if (j == NULL)
    {
        return i->data;
    }
    if (j->next == NULL)
    {
        return i->next->data;
    }
}
