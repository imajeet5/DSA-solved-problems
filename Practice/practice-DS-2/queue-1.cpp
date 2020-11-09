#include <bits/stdc++.h>

using namespace std;

class Queue
{
    int *arr;
    int firstIndex;
    int nextIndex;
    int size;
    int capacity;

public:
    Queue()
    {
        capacity = 5;
        arr = new int[capacity];
        nextIndex = 0;
        firstIndex = 0;
        size = 0;
    };

    Queue(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
        firstIndex = 0;
        size = 0;
    };
    int getSize()
    {
        return size;
    };
    bool empty()
    {
        return size == 0;
    };

    void push(int element)
    {
        if (size == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }

        arr[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
    }

    void pop()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        firstIndex = (firstIndex + 1) % capacity;
        size--;
    }
    int front()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return 0;
        }

        return arr[firstIndex];
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
    cout << q.front() << endl;
    q.pop();

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

    return 0;
}