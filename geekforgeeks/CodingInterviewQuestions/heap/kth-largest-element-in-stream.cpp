// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class MyPriorityQueue {
    // minimum pq
    priority_queue<int, vector<int>, greater<int>> pq;
    int size = 0;
    int capacity = 1;
    int kthMax = 0;
public:
    MyPriorityQueue(int cap) {
        capacity = cap;
    }

    int getKthLargest() {
        if (size == capacity) {
            kthMax = pq.top();
            return kthMax;
        }
        return -1;
    }
    void add(int num) {
        // if size is less than capacity the we directly add to the priority queue
        if (size < capacity) {
            pq.push(num);
            size++;
        }
        else
            if (size == capacity) {
                // mean the priority queue is full
                // and we only add element to the priority queue if num is greater then the current kth max
                // we can remove this condition and put push operation first 
                if (num > kthMax) {
                    // we will remove the lowest element 
                    pq.pop();
                    pq.push(num);
                }
            }
    }
};


class Solution {
public:
    vector<int> kthLargest(int k, int arr[], int n) {

        MyPriorityQueue mpq(k);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            mpq.add(arr[i]);
            ans.push_back(mpq.getKthLargest());
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {

            cin >> arr[i];
        }

        Solution ob;
        vector<int> v = ob.kthLargest(k, arr, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends