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

class Queue
{
    Node *head;
    Node *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(int data)
    {
        Node *n = new Node(data);
        size++;
        if (head == NULL)
        {
            head = n;
            tail = n;
            return;
        }

        tail->next = n;
        tail = tail->next;
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        // we will move the head to one pointer next and delete the current head;
        Node *currHead = head;
        head = head->next;
        currHead->next = NULL;
        delete currHead;
        size--;
    }

    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }

        return head->data;
    }

    bool empty()
    {
        return size == 0;
    }
};

int main(int argc, char const *argv[])
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    q.pop();
    q.push(11);
    q.push(21);
    q.push(31);
    q.push(41);
    q.push(51);
    q.push(61);
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}