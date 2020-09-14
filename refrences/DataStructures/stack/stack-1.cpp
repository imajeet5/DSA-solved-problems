#include <bits/stdc++.h>

using namespace std;

class Stack
{
private:
    int *arr;
    int nextIndex;
    int capacity;

public:
    // default contructor. If user not giving the size then it is 4
    Stack()
    {
        capacity = 4;
        arr = new int[capacity];
        nextIndex = 0;
    };
    Stack(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        nextIndex = 0;
    }
    // return number of elements present in the stack
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    void push(int el)
    {
        if (nextIndex == capacity)
        {
            cout << "Stack full" << endl;
            return;
        }
        arr[nextIndex] = el;
        nextIndex++;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack empty" << endl;
            return;
        }
        nextIndex--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack empty" << endl;
            return INT_MIN;
        }

        return arr[nextIndex - 1];
    }
};

int main(int argc, char const *argv[])
{
    Stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();

    Stack s2(10);
    for (int i = 1; i < 10; i++)
    {
        s2.push(i);
    }

    while (!s2.isEmpty())
    {
        cout << s2.top() << endl;
        s2.pop();
    }

    cout << s2.size() << endl;

    // cout << s.top() << endl;
    // s.pop();
    // cout << s.top() << endl;
    // s.pop();

    return 0;
}