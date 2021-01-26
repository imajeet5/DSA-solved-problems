//
/**
 * CBT:
 * For a CBT all levels are fillled except the last level
 * In CBT we have to fill the level from left to right
 *
 * Minimum number of nodes in a CBT of heigh h is 2^(h-1)
 * Maximum number of node in a CBT of height h is 2^h -1
 * In a CBT height of tree is alway (logN)
 * So in balanced BST we have to do lot of calculations so that our height remains logN but in CBT height is always logN without us doing anything. So no balancing is required in CBT
 * We can store a CBT in an array, with left child present at (2i+1) and right child present at (2i+2) where i is the index of parent child.
 * For getting the parent index when we know the child index use pI = (cI -1)/2
 *
 * For min heap: root < left and root < right
 * For max heap: root > left and root > right
 *
 * So heap is basically a CBT which satisfies the above heap order property
 *
 */

#include <bits/stdc++.h>

using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue() {}

    bool isEmpty() {
        return pq.size() == 0;
    }

    // number of element present in the priority queue
    int getSize() {
        return pq.size();
    }

    int getMin() {
        if (isEmpty()) {
            return 0; // mean priority queue is empty
        }
        return pq[0];
    }

    void insert(int element) {
        pq.push_back(element); // CBT is correct, but we need to heapify the tree
        upHeapify();
    }

    int removeMin() {
        if (isEmpty()) {
            return 0;
        }
        int ans = pq[0];
        swap(pq[0], pq[pq.size() - 1]);

        pq.pop_back();

        downHeapify();

        return ans;
    }


private:
    void upHeapify() {
        // Algo: 1. as the element has been added at the end so we get it index in cI
        //2. We get the index of the parent element and compare element at child index with the parent index
        //3. In case of min Heap if element at child Index is smaller then the value at parent index then we swap
        //4. If element at parent index is smaller then element at chid index then we stop as it is heapified
        //5. otherwise if cI == 0 i.e element has move to the top of heap then also we stop
        
        int cI = pq.size() - 1; // child index
        

        while (cI > 0) {
            int pI = (cI - 1) / 2; // parent index
            if (pq[cI] < pq[pI]) {

                swap(pq[cI], pq[pI]);
                cI = pI;

            }
            else {
                break;
            }
        }
    }

    void downHeapify() {
        int pi = 0;
        while (true) {
            // we get both the left and right side child index
            int lci = 2 * pi + 1;
            int rci = 2 * pi + 2;
            int minIndex = pi;
            // then we find the minimum of the two and get the minIndex
            if (lci < pq.size() && pq[lci] < pq[minIndex]) {
                minIndex = lci;
            }
            if (rci < pq.size() && pq[rci] < pq[minIndex]) {
                minIndex = rci;
            }
            if (minIndex == pi) {
                // the minIndex is equal to the parent index then we assume that our heap order property has been
                // satisfied and we will break
                break;
            }
            // we swap the current parent index with the value at minIndex            
            swap(pq[pi], pq[minIndex]);
            // now we will move down the tree and assign the pi to the minIndex
            pi = minIndex;


        }


    }

};

int main(int argc, char const* argv[]) {
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);
    

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    while (!p.isEmpty()) {
        cout << p.removeMin() << " ";
    }
    cout << endl;

    return 0;
}