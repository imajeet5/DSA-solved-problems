#include <bits/stdc++.h>

using namespace std;

void reverseQueue(queue<int> &q)
{
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main(int argc, char const *argv[])
{
    queue<int> q;
    // q {1,2,3,4,5}
    for (int i = 1; i <= 5; i++)
    {
        q.push(i);
    }

    reverseQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}