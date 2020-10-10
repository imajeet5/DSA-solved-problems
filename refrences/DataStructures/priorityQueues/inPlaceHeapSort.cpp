#include <bits/stdc++.h>

using namespace std;

void inplaceHeapSort(int *input, int n)
{
    // Build the heap in input array
    // we will start traversing from 1 as the the 0th index is already in the heap
    for (int i = 1; i < n; i++)
    {
        int cI = i;
        // here we will do up heapify
        // current element will be compared with the above element and if the it is smaller then we will swap and repeat the process
        // for the new above element
        while (cI > 0)
        {
            int pI = (cI - 1) / 2;
            if (input[cI] < input[pI])
            {
                swap(input[cI], input[pI]);
                cI = pI;
            }
            else
            {
                break;
            }
        }
    }

    // remove min n times
    int size = n;

    while (size >= 1)
    {
        swap(input[0], input[size - 1]);
        size--; // we are decreasing the size to indicate that element has been removed
        // down Heapify
        int pi = 0;

        while (true)
        {
            int lci = 2 * pi + 1;
            int rci = 2 * pi + 2;
            int minIndex = pi;
            if (lci < size && input[lci] < input[minIndex])
            {
                minIndex = lci;
            }
            if (rci < size && input[rci] < input[minIndex])
            {
                minIndex = rci;
            }
            if (minIndex == pi)
            {
                break;
            }
            swap(input[pi], input[minIndex]);

            pi = minIndex;
        }
    }
}

int main(int argc, char const *argv[])
{
    int input[] = {5, 1, 2, 0, 8};
    inplaceHeapSort(input, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;

    return 0;
}