

#include <bits/stdc++.h>

using namespace std;

// implementing using Arrays

class Stack
{
private:
    int *arr;
    int nextIndex;
    int capacity;

public:
    Stack()
    {
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0;
    }

    Stack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }

    int size()
    {
        return nextIndex;
    }

    bool isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            cout << "Cannot insert " << element << " stack full " << endl;
            return;
        }

        arr[nextIndex] = element;
        nextIndex++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return;
        }

        nextIndex--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty " << endl;
            return INT_MIN;
        }

        return arr[nextIndex - 1];
    }
};

int main(int argc, char const *argv[])
{
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    cout << "Stack size is " << s.size() << endl;

    return 0;
}