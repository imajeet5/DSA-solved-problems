#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int ele)
    {
        this->data = ele;
        this->next = NULL;
    }
};

void printLinkedList(Node *head)
{

    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }

    cout << "NULL" << endl;
}

Node *takeInputHead()
{
    Node *head = NULL;
    Node *tail = NULL;

    int data;
    cin >> data;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        cin >> data;
    }

    return head;
}

Node *takeInputTail()
{
    Node *head = NULL;
    Node *tail = NULL;

    int data;
    cin >> data;

    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }

        cin >> data;
    }

    return head;
}

int lengthOfLinkedList(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

void printithNode(Node *head, int i)
{
    if (i < 0)
    {
        cout << "Node does not exist" << endl;
        return;
    }
    int count = 0;
    while (count < i && head != NULL)
    {
        head = head->next;
        count++;
    }
    if (head)
    {
        cout << "Element at " << i << "th position is " << head->data << endl;
    }
    else
    {
        cout << "Node does not exist" << endl;
    }
}

Node *insertAtIthPosition(Node *head, int data, int pos)
{
    if (pos < 0)
    {
        cout << "Out of range" << endl;
        return head;
    }

    Node *newNode = new Node(data);
    // insert node at head
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
        return head;
    }

    Node *thead = head;

    while ((pos - 1) && thead)
    {
        thead = thead->next;
        pos--;
    }

    // Now either traversalHead is null or pos == 0
    if (thead == NULL)
    {
        cout << "Out of range" << endl;
        delete newNode;
        return head;
    }
    newNode->next = thead->next;
    thead->next = newNode;
    return head;
}

int main(int argc, char const *argv[])
{

    Node *head = new Node(10);
    Node *tail = head;
    cout << tail << endl;
    cout << head << endl;

    for (int i = 2; i < 10; i++)
    {
        tail->next = new Node(i * 10);
        tail = tail->next;
    }

    printLinkedList(head);
    printLinkedList(head);

    Node *userLL1 = takeInputTail();

    printLinkedList(userLL1);

    int element, pos;

    cout << "Enter element and position to insert " << endl;
    cin >> element >> pos;

    userLL1 = insertAtIthPosition(userLL1, element, pos);

    cout << "length of list " << lengthOfLinkedList(userLL1) << endl;

    for (size_t i = 0; i < lengthOfLinkedList(userLL1); i++)
    {
        printithNode(userLL1, i);
    }

    Node *userLL2 = takeInputHead();

    printLinkedList(userLL2);

    cout << "Enter element and position to insert " << endl;
    cin >> element >> pos;

    userLL2 = insertAtIthPosition(userLL2, element, pos);

    cout << "length of list " << lengthOfLinkedList(userLL2) << endl;

    for (size_t i = 0; i < lengthOfLinkedList(userLL2); i++)
    {
        printithNode(userLL2, i);
    }

    return 0;
}