#include <bits/stdc++.h>

using namespace std;

class Stack
{
private:
    int *arr;
    int capacity;
    int nextIndex;

public:
    Stack()
    {
        capacity = 2;
        arr = new int[capacity];
        int nextIndex;
    }

    int getSize()
    {
        return nextIndex;
    }

    int isEmpty()
    {
        return nextIndex == 0;
    }

    void push(int element)
    {
        if (nextIndex == capacity)
        {
            capacity = 2 * capacity;
            int *newarr = new int[capacity];
            for (int i = 0; i < nextIndex; i++)
            {
                newarr[i] = arr[i];
            }
            delete[] arr;
            arr = newarr;
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
    int size()
    {
        return nextIndex;
    }

    int getCapacity()
    {
        return capacity;
    }
};

int main(int argc, char const *argv[])
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    cout << "Stack size is " << s.size() << endl;

    while (!s.isEmpty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}