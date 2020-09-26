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
        next = NULL;
    }
};

class Queue
{
private:
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

    bool isEmpty()
    {
        return size == 0;
    }

    int getSize()
    {
        return size;
    }

    void push(int element)
    {
        Node *newnode = new Node(element);

        if (head == NULL)
        {
            head = newnode;
            tail = head;
            size++;
            return;
        }

        tail->next = newnode;
        tail = tail->next;
        size++;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }

        return head->data;
    }
};

int main(int argc, char const *argv[])
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.pop();
    q.pop();
    q.push(40);
    q.push(50);
    q.push(60);
    q.pop();
    q.push(70);
    q.push(80);
    q.push(90);
    q.push(100);
    q.push(110);
    q.push(120);

    cout << "size " << q.getSize() << endl;
    while (!q.isEmpty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    cout << q.front() << endl;
    q.pop();
    q.push(1);
    q.push(2);
    q.push(3);
    while (!q.isEmpty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}