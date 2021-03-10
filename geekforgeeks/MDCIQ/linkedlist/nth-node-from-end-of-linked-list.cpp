
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

/* Function to get the nth node from the last of a linked list*/
int getNthFromLast(struct Node *head, int n);

/* Driver program to test above function*/
int main()
{
    int T, i, n, l, k;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL, *tail = NULL;

        cin >> n >> k;
        int firstdata;
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }

        cout << getNthFromLast(head, k) << endl;
    }
    return 0;
} // } Driver Code Ends

/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n)
{
    // Your code here
    if (head == NULL)
    {
        return -1;
    }

    Node *p1 = head;
    Node *p2 = head;

    for (int i = 1; i < n; i++)
    {
        p1 = p1->next;
        // this case handle when the value of i is greater then the length of the list
        if (p1 == NULL && i < n)
            return -1;
    }
    // if p1 has reached the end of the list that means we have to return the first element of the list
    if (p1 == NULL)
        return p2->data;
    // otherwise move both pointer until p1 reaches null
    while (p1->next)
    {
        p1 = p1->next;
        p2 = p2->next;
    }
    return p2->data;
}
