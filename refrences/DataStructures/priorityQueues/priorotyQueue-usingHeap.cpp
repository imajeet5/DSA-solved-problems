#include <bits/stdc++.h>

using namespace std;

class PriorityQueue
{
    vector<int> pq;

public:
    PriorityQueue()
    {
    }
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    // Return the size of the priority queue - no of elements present
    int getSize()
    {
        return pq.size();
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        return pq[0];
    }

    void insert(int element)
    {
        pq.push_back(element); // CBT is satisfied but heap property is not satisfied
        int cI = pq.size() - 1;

        while (cI > 0)
        {
            // get the parent index
            int pI = (cI - 1) / 2;
            // if child index is smaller then the parent index, then we will swap as it is the min heap and cI is now pI
            if (pq[cI] < pq[pI])
            {
                swap(pq[cI], pq[pI]);
                cI = pI;
            }
            else
            {
                break;
            }
        }
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }

        int result = pq[0];

        // swap first and the last element and remove the last element
        swap(pq[0], pq[pq.size() - 1]);
        pq.pop_back();

        // CBT yes, Heap no
        // Down Heapify

        int pI = 0;
        while (true)
        {
            int lci = 2 * pI + 1;
            int rci = 2 * pI + 2;
            int minIndex = pI;

            // if it is a valid index and child element is less then the current element then set minIndex to that
            if (lci < pq.size() && pq[lci] < pq[minIndex])
            {
                minIndex = lci;
            }
            if (rci < pq.size() && pq[rci] < pq[minIndex])
            {
                minIndex = rci;
            }

            // if the minIndex still same as the parent index the element is at it right place and we need not to continue further.
            if (minIndex == pI)
            {
                break;
            }

            // minIndex is the index of child elements of pI which is smaller then the parent index
            swap(pq[pI], pq[minIndex]);

            // now as the pI value is swapped with the minIndex value we will replace the parent index with the minIndex
            pI = minIndex;
        }

        return result;
    }
};

int main(int argc, char const *argv[])
{
    PriorityQueue p;
    p.insert(100);
    p.insert(10);
    p.insert(15);
    p.insert(15);
    p.insert(4);
    p.insert(17);
    p.insert(21);
    p.insert(67);

    cout << p.getSize() << endl;
    cout << p.getMin() << endl;

    while (!p.isEmpty())
    {
        cout << p.removeMin() << " ";
    }

    return 0;
}