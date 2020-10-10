/*
we are given two thing as input:
1. array a [] = {10, 12, 15, 6,9}
2. value of k = 3

We have to find k-smallest elements
*/

#include <bits/stdc++.h>

using namespace std;

void kSmallest(int *arr, int n, int k)
{
    priority_queue<int> pq;

    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (size_t i = k; i < n; i++)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // ans
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

void kSmallest2(int *arr, int n, int k)
{
    priority_queue<int> pq;
    for (size_t i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {5, 6, 9, 12, 3, 13, 2};

    kSmallest2(a, 7, 3);

    return 0;
}