#include <bits/stdc++.h>

using namespace std;

class MyStackUsingTwoQueues
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStackUsingTwoQueues()
    {
    }

    void push(int x)
    {
        // first we push the element to q2
        q2.push(x);
        // then we transfer all the elements of q1 to q2
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        // then we swap q1 and q2
        swap(q1, q2);
    }

    int pop()
    {
        // as we are storing the elemets in q1 in the order in which then are provided
        // so we will remove the first element from q1
        int n = q1.front();
        q1.pop();
        return n;
    }

    int top()
    {

        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};

class MyStackUsingSingleQueue
{
public:
    queue<int> q1;
    MyStackUsingSingleQueue()
    {
    }

    void push(int x)
    {
        // first we push the element in the queue
        q1.push(x);
        //for we will put all the elements from the start to the end of the queue
        for (int i = 0; i < q1.size() - 1; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }
    }

    int pop()
    {
        // as we are storing the elemets in q1 in the order in which then are provided
        // so we will remove the first element from q1
        int n = q1.front();
        q1.pop();
        return n;
    }

    int top()
    {

        return q1.front();
    }

    bool empty()
    {
        return q1.empty();
    }
};