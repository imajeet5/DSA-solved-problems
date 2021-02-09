// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }

};

Node* mergeKLists(Node* arr[], int N);

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        struct Node* arr[N];
        for (int j = 0;j < N;j++) {
            int n;
            cin >> n;

            int x;
            cin >> x;
            arr[j] = new Node(x);
            Node* curr = arr[j];
            n--;

            for (int i = 0;i < n;i++) {
                cin >> x;
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
        }

        Node* res = mergeKLists(arr, N);
        printList(res);

    }

    return 0;
}
// } Driver Code Ends


/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

/* arr[] is an array of pointers to heads of linked lists
  and N is size of arr[]  */

  // this solution has the time complexity of O(NlogN)
Node* mergeKLists(Node* arr[], int N) {
    //Plan: 1. traverse through each list and push in min priority queue
    //2. create a new list with head at the root of pq
    //3. Now traverse throught the priority queue and append each element at the end of list


    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; i++) {
        Node* head = arr[i];
        while (head) {
            pq.push(head->data);
            head = head->next;
        }
    }

    Node* root = new Node(pq.top());
    pq.pop();
    Node* tail = root;
    while (!pq.empty()) {
        tail->next = new Node(pq.top());
        tail = tail->next;
        pq.pop();
    }
    return root;
}

// there can also be one another approach to solve this problem in O(NlogK) time. 