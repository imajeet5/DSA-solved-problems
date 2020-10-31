// { Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;

/* Link list Node */
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

int intersectPoint(struct Node *head1, struct Node *head2);
int intersectPoint2(struct Node *head1, struct Node *head2);
int intersectPoint3(struct Node *head1, struct Node *head2);

Node *inputList(int size)
{
    if (size == 0)
        return NULL;

    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

/* Driver program to test above function*/
int main()
{
    int T, n1, n2, n3;

    cin >> T;
    while (T--)
    {
        cin >> n1 >> n2 >> n3;

        Node *head1 = inputList(n1);
        Node *head2 = inputList(n2);
        Node *common = inputList(n3);

        Node *temp = head1;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        temp = head2;
        while (temp != NULL && temp->next != NULL)
            temp = temp->next;
        if (temp != NULL)
            temp->next = common;

        cout << intersectPoint(head1, head2) << endl;
    }
    return 0;
}

// } Driver Code Ends

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int intersectPoint(Node *head1, Node *head2)
{
    // Your Code Here
    stack<Node *> s1;
    stack<Node *> s2;
    Node *curr1 = head1;
    Node *curr2 = head2;
    while (curr1 != NULL)
    {
        s1.push(curr1);
        curr1 = curr1->next;
    }

    while (curr2 != NULL)
    {
        s2.push(curr2);
        curr2 = curr2->next;
    }

    int y = -1;
    while (!s1.empty() && !s2.empty())
    {
        if (s1.top() == s2.top())
        {
            y = s1.top()->data;
            s1.pop();
            s2.pop();
        }
        else
        {
            break;
        }
    }

    return y;
}

int lengthOfList(Node *head)
{
    int l = 0;
    while (head)
    {
        l++;
        head = head->next;
    }
    return l;
}
// not working
int intersectPoint2(Node *head1, Node *head2)
{
    int n = lengthOfList(head1);
    int m = lengthOfList(head2);
    Node *longerList;
    Node *sorterList;

    int d;
    if (n <= m)
    {
        d = m - n;
        longerList = head2;
    }
    else
    {
        d = n - m;
        longerList = head1;
    }

    while (d--)
    {
        longerList = longerList->next;
    }

    while (sorterList && longerList)
    {
        if (sorterList == longerList)
        {
            return sorterList->data;
        }

        sorterList = sorterList->next;
        longerList = longerList->next;
    }
}

int intersectPoint3(struct Node *head1, struct Node *head2)
{
    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node *A = head1;
    Node *B = head2;

    while (A != B)
    {
        if (A == NULL)
        {
            A = head2;
        }
        else
        {
            A = A->next;
        }

        if (B == NULL)
        {
            B = head1;
        }
        else
        {
            B = B->next;
        }
    }
    if (A)
        return A->data;
    return NULL;
};