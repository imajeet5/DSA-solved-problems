#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    priority_queue<int> pq;
    pq.push(16);
    pq.push(1);
    pq.push(167);
    pq.push(7);
    pq.push(45);
    pq.push(32);

    cout << "Size " << pq.size() << endl;

    cout << "Top :" << pq.top() << endl;

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    cout << "Size " << pq.size() << endl;

    cout << "**************Min Priority Queue Starts ***********" << endl;

    priority_queue<int, vector<int>, greater<int>> pq2; // creating min priority queue

    pq2.push(16);
    pq2.push(1);
    pq2.push(167);
    pq2.push(7);
    pq2.push(45);
    pq2.push(32);

    cout << "Size " << pq2.size() << endl;

    cout << "Top :" << pq2.top() << endl;

    while (!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;

    cout << "Size " << pq2.size() << endl;

    return 0;
}