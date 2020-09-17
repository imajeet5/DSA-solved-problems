#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }
};

// insert node at the back of the Node
Node *insertEnd(Node *head, int data)
{

    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    //traverse at the end of node

    Node *tail = head;

    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->prev = tail;
    return head;
}

Node *insertFront(Node *head, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        return head;
    }
    newNode->next = head;
    head = newNode;
    return head;
}

Node *insertithPosition(Node *head, int pos, int data)
{
    Node *thead = head;
    if (pos < 0)
    {
        cout << "Out of range" << endl;
        return head;
    }
    // if pos is 0
    if (pos == 0)
    {
        return insertFront(head, data);
    }

    while ((pos - 1) && thead)
    {
        thead = thead->next;
        pos--;
    }

    if (thead == NULL)
    {
        cout << "Out of range" << endl;
        return head;
    }
    Node *newNode = new Node(data);
    newNode->next = thead->next;
    newNode->prev = thead;
    thead->next = newNode;
    newNode->next->prev = newNode;
    return head;
}

Node *deleteithPosition(Node *head, int pos)
{
    Node *thead = head;
    if (pos < 0)
    {
        cout << "Out of range" << endl;
        return head;
    }
    // remove the first element
    if (pos == 0)
    {
        Node *nextNode = head->next;
        nextNode->prev = NULL;
        head->next = NULL;
        delete head;
        return nextNode;
    }

 
    while ((pos - 1) && thead)
    {
        thead = thead->next;
        pos--;
    }
    if (thead == NULL || thead->next == NULL)
    {
        cout << "Out of range" << endl;
        return head;
    }
    // remove the last node
    if (thead->next->next == NULL)
    {
        Node *lastNode = thead->next;
        lastNode->prev = NULL;
        
        thead->next = NULL;
        delete lastNode;
        return head;
    }
    Node *removedNode = thead->next;
    thead->next = removedNode->next;
    removedNode->next->prev = thead;
    removedNode->next = NULL;
    removedNode->prev = NULL;
    delete removedNode;
    return head;
}

void printDLL(Node *head)
{
    Node *tail = NULL;
    cout << "Forward Traversal:  ";

    cout << "NULL<>";
    while (head != NULL)
    {
        cout << head->data << "<>";
        tail = head;
        head = head->next;
    }
    cout << "NULL" << endl;

    cout << "Backward Traversal:  ";

    cout << "NULL<>";
    while (tail != NULL)
    {
        cout << tail->data << "<>";
        tail = tail->prev;
    }
    cout << "NULL" << endl;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;

    head = insertEnd(head, 1);
    head = insertEnd(head, 2);
    head = insertEnd(head, 3);
    // head = insertEnd(head, 4);
    // head = insertEnd(head, 5);

    head = deleteithPosition(head, 0);

    printDLL(head);

    return 0;
}

/**
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */

//**************************Insert Using pointers*******************************
void append(Node **head_ref, int new_data)
{
    /* 1. allocate node */
    Node *new_node = new Node(new_data);

    Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */

    /* 4. If the Linked List is empty, then make the new  
        node as head */
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}