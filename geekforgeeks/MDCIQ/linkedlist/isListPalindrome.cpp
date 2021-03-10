// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
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

bool isPalindrome(Node *head);
bool isPalindrome2(Node *head);
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        cout << isPalindrome2(head) << endl;
    }
    return 0;
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
/*You are required to complete this method */
bool isPalindrome(Node *head)
{

    //Your code here
    if (head == NULL)
    {
        return false;
    }
    Node *temp = head;
    stack<int> stk;
    while (temp)
    {
        stk.push(temp->data);
        temp = temp->next;
    }
    while (!stk.empty())
    {
        if (head->data != stk.top())
        {
            return false;
        }
        head = head->next;
        stk.pop();
    }
    return true;
}

bool isPalindrome2(Node *head)
{
    //Your code here
    if (head == NULL)
    {
        return false;
    }
    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;

        // reverse the list
        Node *current = slow;
        slow = slow->next;
        current->next = prev;
        prev = current;
    }

    //Handling the case of odd length of the list
    if (fast != NULL)
        slow = slow->next;

    while (prev && slow)
    {
        if (prev->data != slow->data)
            return false;
        prev = prev->next;
        slow = slow->next;
    }
    return true;
}
