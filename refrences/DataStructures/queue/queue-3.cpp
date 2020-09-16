// queue using linked list

#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = nullptr;
    }
};

template <typename T>
class Queue
{
private:
    Node<T> *head;
    Node<T> *tail;
    int size;

public:
    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    void push(T ele)
    {
        Node<T> *n = new Node<T>(ele);
        size++;
        if (head == NULL)
        {
            head = n;
            tail = head;

            return;
        }
        tail->next = n;
        tail = tail->next;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        return head->data;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
};

int main(int argc, char const *argv[])
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);

    while (!q.isEmpty())
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
    while (!q.isEmpty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}