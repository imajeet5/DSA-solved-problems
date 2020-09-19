#include <bits/stdc++.h>

using namespace std;

class Queue
{
private:
    int *arr;
    int f;
    int n;
    int size;
    int capacity;

public:
    Queue()
    {
        capacity = 5;
        arr = new int[capacity];
        f = 0;
        n = 0;
        size = 0;
    }

    Queue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        f = 0;
        n = 0;
        size = 0;
    }

    void push(int element)
    {
        if (size == capacity)
        {
            cout << "Queue full" << endl;
            return;
        }

        arr[n] = element;
        n = (n + 1) % capacity;
        size++;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty " << endl;
            return;
        }
        // increase the font index by 1 in circular manner
        f = (f + 1) % capacity;
        size--;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }

        return arr[f];
    }

    int getSize()
    {
        return size;
    }
};

int main(int argc, char const *argv[])
{
    Queue q(5);
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
}