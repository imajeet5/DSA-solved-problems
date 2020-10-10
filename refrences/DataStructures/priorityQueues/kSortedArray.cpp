/*
we are given two thing as input:
1. array a [] = {10, 12, 15, 6,9}
2. value of k = 3

after sorting the element has moved only by k - 1 position from it's initial position
*/

#include <bits/stdc++.h>

using namespace std;

void kSortedArray(int *input, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }

    int s = 0;

    for (int i = k; i < n; i++)
    {
        input[s] = pq.top();
        pq.pop();
        s++;
        pq.push(input[i]);
    }
    while (!pq.empty())
    {
        input[s] = pq.top();
        pq.pop();
        s++;
    }
}

int main(int argc, char const *argv[])
{
    int input[] = {10, 12, 6, 7, 9};
    int k = 3;
    kSortedArray(input, 5, k);
    for (size_t i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }

    return 0;
}
