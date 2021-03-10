// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct node *reverse(struct node *head, int k);

struct node
{
    int data;
    struct node *next;

    node(int x)
    {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin >> t;

    while (t--)
    {
        struct node *head = NULL;
        struct node *temp = NULL;
        int n;
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            int value;
            cin >> value;
            if (i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }

        int k;
        cin >> k;

        head = reverse(head, k);
        printList(head);
    }

    return (0);
}

struct node *reverse(struct node *head, int k)
{
    node *current = head;
    node *next = NULL;
    node *prev = NULL;
    int count = 0;

    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    // when we have reverse the list then prev will become head and head will become tail.

    /* next is now a pointer to (k+1)th node  
    Recursively call for the list starting from current.  
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);

    /* prev is new head of the input list */
    return prev;
}

struct node *Reverse(struct node *head, int k)
{
    // Create a stack of Node*
    stack<node *> mystack;
    struct node *current = head;
    struct node *prev = NULL;

    while (current != NULL)
    {

        // Terminate the loop whichever comes first
        // either current == NULL or count >= k
        int count = 0;
        while (current != NULL && count < k)
        {
            mystack.push(current);
            current = current->next;
            count++;
        }

        // Now pop the elements of stack one by one
        while (mystack.size() > 0)
        {

            // If final list has not been started yet.
            if (prev == NULL)
            {
                prev = mystack.top();
                head = prev;
                mystack.pop();
            }
            else
            {
                prev->next = mystack.top();
                prev = prev->next;
                mystack.pop();
            }
        }
    }

    // Next of last element will point to NULL.
    prev->next = NULL;

    return head;
}