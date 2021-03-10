// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

/* Linked list Node */
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

struct Node *buildList(int size)
{
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

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

struct Node *addTwoLists(struct Node *first, struct Node *second);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);

        Node *res = addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

#include <stack>

struct Node *reverseList(struct Node *head)
{
    Node *p = NULL;
    Node *n = NULL;
    while (head)
    {
        n = head->next;
        head->next = p;
        p = head;
        head = n;
    }

    return p;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    // code here
    long long s1 = 0;
    long long s2 = 0;
    long long total = 0;
    while (first)
    {
        s1 = s1 * 10 + first->data;
        first = first->next;
    }
    while (second)
    {
        s2 = s2 * 10 + second->data;
        second = second->next;
    }
    cout << s1 << " " << s2;
    total = s1 + s2;
    if (total == 0)
    {
        return NULL;
    }

    stack<long long> digits;

    while (total)
    {
        int last = total % 10;
        digits.push(last);
        total = (total - last) / 10;
    }

    Node *result = new Node(digits.top());
    Node *tail = result;
    digits.pop();
    while (digits.size() > 0)
    {
        tail->next = new Node(digits.top());
        tail = tail->next;
        digits.pop();
    }

    return result;
}

struct Node *addTwoLists2(struct Node *first, struct Node *second)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;

    int carry = 0;
    
    first = reverseList(first);
    second = reverseList(second);

    while (first || second || carry)
    {
        int sum = 0;
        if (first)
        {
            sum += first->data;
            first = first->next;
        }

        if (second)
        {
            sum += second->data;
            second = second->next;
        }

        sum += carry;
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }

    return reverseList(dummy->next);
}

struct Node *addTwoListsReverse(struct Node *first, struct Node *second)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;

    int carry = 0;

    while (first || second || carry)
    {
        int sum = 0;
        if (first)
        {
            sum += first->data;
            first = first->next;
        }

        if (second)
        {
            sum += second->data;
            second = second->next;
        }

        sum += carry;
        carry = sum / 10;
        temp->next = new Node(sum % 10);
        temp = temp->next;
    }

    return dummy->next;
}

//https://www.geeksforgeeks.org/sum-of-two-linked-lists/