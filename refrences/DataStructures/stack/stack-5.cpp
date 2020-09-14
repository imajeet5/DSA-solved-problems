// stack using linked list

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
class Stack
{
private:
    Node<T> *head;
    int size;

public:
    Stack()
    {
        head = NULL;
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

    void push(int ele)
    {
        // this code is automatically handling the case of head == NULL
        Node<T> *n = new Node<T>(ele);
        n->next = head;
        head = n;
        size++;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return 0;
        }
        return head->data;
    }
};

int main(int argc, char const *argv[])
{
    Stack<char> s;
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;

    cout << s.getSize() << endl;
    cout << s.isEmpty() << endl;
    // s.pop();
    return 0;
}