// { Driver Code Starts
// C++ program for implementation of Heap Sort
#include <bits/stdc++.h>
using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i);

void buildHeap(int arr[], int n);

// main function to do heap sort
void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}


/* Function to print an array */
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Driver program to test above functions
int main() {
    int arr[1000000], n, T, i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (i = 0;i < n;i++)
            scanf("%d", &arr[i]);
        heapSort(arr, n);
        printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends


/* Main function to do heap sort. This function uses buildHeap()
   and heapify()
void heapSort(int arr[], int n)  {
    buildHeap(arr, n);
    for (int i=n-1; i>=0; i--)  {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
} */
// The functions should be written in a way that array become sorted 
// in increasing order when above heapSort() is called.
// To heapify a subtree rooted with node i which is  an index in arr[]. 
// n is size of heap. This function  is used in above heapSor()


// we are doing max heap code 
// with max heap code we get the array sorted in ascending order as in our remove function we remove element from the last 
// and at last we have the maximum element
// similarly if we use min heap code we get array sorted in descending order
// to get in descending just replace all ">"  => with "<"
void heapify(int* pq, int size, int i) {
    // Your Code Here
    int pi = i;
    while (true) {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int minIndex = pi;
        // we will get the minimum of the two child
        if (lci < size && pq[lci] > pq[minIndex]) {
            minIndex = lci;
        }
        if (rci < size && pq[rci] > pq[minIndex]) {
            minIndex = rci;
        }

        if (minIndex == pi) {
            break;
        }
        swap(pq[pi], pq[minIndex]);
        pi = minIndex;
    }
}

void upHeapify(int* pq, int lastIndex) {
    int ci = lastIndex;
    while (ci > 0) {
        int pi = (ci - 1) / 2;
        if (pq[ci] > pq[pi]) {
            swap(pq[ci], pq[pi]);
            ci = pi;
        }
        else {
            break;
        }
    }

}


// Rearranges input array so that it becomes a max heap
void buildHeap(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        upHeapify(arr, i);
    }
}