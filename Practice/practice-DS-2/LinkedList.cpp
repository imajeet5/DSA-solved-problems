#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void inputUpdateTail(Node *tail)
{
    int n = 0;
    cout << "Enter a number: " << endl;
    cin >> n;
    while (n != -1)
    {

        Node *new_node = new Node(n);
        tail->next = new_node;
        tail = new_node;
        cout << "Enter a number: " << endl;
        cin >> n;
    }
}

Node *inputUpdateHead(Node *head)
{
    int n = 0;
    cout << "Enter a number: " << endl;
    cin >> n;
    while (n != -1)
    {
        Node *new_node = new Node(n);
        new_node->next = head;
        head = new_node;
        cout << "Enter a number: " << endl;
        cin >> n;
    }

    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main(int argc, char const *argv[])
{

    Node *head = new Node(1);
    Node *n1 = new Node(2);
    Node *n2 = new Node(3);
    head->next = n1;
    n1->next = n2;
    inputUpdateTail(n2);
    head = inputUpdateHead(head);
    printList(head);
    return 0;
}