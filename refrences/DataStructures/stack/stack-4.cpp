#include <bits/stdc++.h>

// using templats

using namespace std;

template <typename T>
class Stack
{
private:
    T *arr;
    int nextIndex;
    int capacity;

public:
    // default contructor. If user not giving the size then it is 4
    Stack()
    {
        capacity = 4;
        arr = new T[capacity];
        nextIndex = 0;
    };

    // return number of elements present in the stack
    int size()
    {
        return nextIndex;
    }
    bool isEmpty()
    {
        return nextIndex == 0;
    }
    void push(T el)
    {
        if (nextIndex == capacity)
        {
            T *newArr = new T[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = 2 * capacity;
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

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack empty" << endl;
            return 0;
        }

        return arr[nextIndex - 1];
    }
};

int main(int argc, char const *argv[])
{
    Stack<char> s;
    s.push(100);
    s.push(101);
    s.push(102);
    s.push(103);
    s.push(104);

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
    s.pop();

    Stack<int> s2;
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