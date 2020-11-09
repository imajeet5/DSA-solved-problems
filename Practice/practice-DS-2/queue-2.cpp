#include <bits/stdc++.h>

using namespace std;

class Queue
{
    int *arr;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

public:
    Queue()
    {
        capacity = 5;
        arr = new int[capacity];
        firstIndex = 0;
        nextIndex = 0;
        size = 0;
    }

    bool empty()
    {
        return size == 0;
    }

    void push(int element)
    {
        // increasing the size of the queue if it is full
        if (size == capacity)
        {
            int *newArr = new int[2 * capacity];
            int j = 0;
            for (int i = firstIndex; i < capacity; i++)
            {
                newArr[j] = arr[i];
                j++;
            }

            for (int i = 0; i < firstIndex; i++)
            {
                newArr[j] = arr[i];
                j++;
            }

            firstIndex = 0;
            nextIndex = capacity;
            capacity = 2 * capacity;
            delete[] arr;
            arr = newArr;
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
    q.push(7);
    q.push(8);
    q.push(9);

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);
    q.push(9);

    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}