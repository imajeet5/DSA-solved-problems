#include <bits/stdc++.h>

using namespace std;

// Queue using circular array
template <typename T>
class Queue
{
private:
    T *arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    Queue()
    {
        capacity = 5;
        arr = new T[capacity];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    }

    Queue(int cap)
    {
        capacity = cap;
        arr = new T[capacity];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    };
    int getSize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    // insert element
    void push(int ele)
    {
        if (size == capacity)
        {
            cout << "Queue full";
            return;
        }
        arr[nextIndex] = ele;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
        {
            firstIndex = 0;
        }
        size++;
    }
    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }

        return arr[firstIndex];
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }

        firstIndex = (firstIndex + 1) % capacity;
        size--;
        // this code is optional as when size == 0, user will not able to read the front element of the array
        // resetting  or not resetting the variable does not matter
        if (size == 0)
        {
            // reset variables
            nextIndex = 0;
            firstIndex = -1;
        }
    }
};

int main(int argc, char const *argv[])
{
    Queue<int> q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

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