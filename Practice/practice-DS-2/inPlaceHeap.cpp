#include <bits/stdc++.h>

using namespace std;

// we do upheapify while making the heap so the lowest element will be at the top
void upHeapify(int* pq, int lastIndex) {
    int ci = lastIndex;
    while (ci > 0) {
        int pi = (ci - 1) / 2;
        if (pq[ci] < pq[pi]) {
            swap(pq[ci], pq[pi]);
            ci = pi;
        }
        else {
            break;
        }
    }

}


// we will do downheapify while doing the removing operation of the heap
void downHeapify(int* pq, int size) {
    int pi = 0;
    while (true) {
        int lci = 2 * pi + 1;
        int rci = 2 * pi + 2;
        int minIndex = pi;
        // we will get the minimum of the two child
        if (lci < size && pq[lci] < pq[minIndex]) {
            minIndex = lci;
        }
        if (rci < size && pq[rci] < pq[minIndex]) {
            minIndex = rci;
        }

        if (minIndex == pi) {
            break;
        }
        swap(pq[pi], pq[minIndex]);
        pi = minIndex;
    }
}

void inPlaceHeapSort(int* pq, int n) {
    // Build the heap in input array by perfroming the upHeapify operation on array n-1 times as 0th element is already in heap
    for (int i = 1; i < n; i++) {
        upHeapify(pq, i);
    }
    // we will perform the downHeapify operation n time
    for (int i = n - 1; i >= 0; i--) {
        swap(pq[0], pq[i]);
        downHeapify(pq, i);
    }







}


int main(int argc, char const* argv[]) {
    int x{};
    cout << "Enter a integer" << endl;
    cin >> x;
    cout << "Result: " << x << endl;
    return 0;
}