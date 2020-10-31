// { Driver Code Starts
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

Node *rotate(struct Node *head, int k);

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, val, k;
        cin >> n;

        cin >> val;
        Node *head = new Node(val);
        Node *tail = head;

        for (int i = 0; i < n - 1; i++)
        {
            cin >> val;
            tail->next = new Node(val);
            tail = tail->next;
        }

        cin >> k;

        head = rotate(head, k);
        printList(head);
    }
    return 1;
}
// } Driver Code Ends

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

// This function should rotate list counter-clockwise
// by k and return new head (if changed)

Node *rotate(Node *head, int k)
{
    // Your code here
    if (k == 0)
        return NULL;

    Node *kthNode; // will store k-1 element
    Node *tail = head;
    while (tail->next)
    {
        if (k == 1)
            kthNode = tail;

        tail = tail->next;
        k--;
    }

    tail->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
    return head;
}

// in this method we make the linked list circular and then break the list at the kth position
Node *rotate2(Node* head_ref, int k)
{
    if (k == 0)
        return;
 
    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.
    Node* current = head_ref;
 
    // Traverse till the end.
    while (current->next != NULL)
        current = current->next;
 
    current->next = head_ref;
    current =head_ref;
 
    // traverse the linked list to k-1 position which
    // will be last element for rotated array.
    for (int i = 0; i < k - 1; i++)
        current = current->next;
 
    // update the head_ref and last element pointer to NULL
    head_ref = current->next;
    current->next = NULL;
    return head_ref;
}

Node *rotate3(Node *head_ref, int k)
{
    if (k == 0)
        return NULL;

    // Let us understand the below
    // code for example k = 4 and
    // list = 10->20->30->40->50->60.
    Node *tail = head_ref;

    // tail will either point to
    // kth or NULL after this loop.
    // tail will point to node
    // 40 in the above example
    int count = 1;
    while (count < k && tail != NULL)
    {
        tail = tail->next;
        count++;
    }

    // If tail is NULL, k is greater than
    // or equal to count of nodes in linked list.
    // Don't change the list in this case
    if (tail == NULL)
        return NULL;

    // tail points to kth node.
    // Store it in a variable. kthNode
    // points to node 40 in the above example
    Node *kthNode = tail;

    // tail will point to
    // last node after this loop
    // tail will point to
    // node 60 in the above example
    while (tail->next != NULL)
        tail = tail->next;

    // Change next of last node to previous head
    // Next of 60 is now changed to node 10
    tail->next = head_ref;

    // Change head to (k+1)th node
    // head is now changed to node 50
    head_ref = kthNode->next;

    // change next of kth node to NULL
    // next of 40 is now NULL
    kthNode->next = NULL;
    return head_ref;
}
