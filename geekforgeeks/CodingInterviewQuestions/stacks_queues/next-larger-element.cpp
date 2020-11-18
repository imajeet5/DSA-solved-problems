// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// Function to store Next larger elements

vector<long long> nextLargerElement2(long long arr[], int n)
{
    // Your code here
    stack<int> s;

    /* push the first element to stack */
    s.push(arr[0]);

    // iterate for rest of the elements
    for (int i = 1; i < n; i++)
    {

        if (s.empty())
        {
            s.push(arr[i]);
            continue;
        }

        /* if stack is not empty, then 
	pop an element from stack. 
	If the popped element is smaller 
	than next, then 
	a) print the pair 
	b) keep popping while elements are 
	smaller and stack is not empty */
        while (s.empty() == false && s.top() < arr[i])
        {
            cout << s.top() << " --> " << arr[i] << endl;
            s.pop();
        }

        /* push next to stack so that we can find 
	next greater for it */
        s.push(arr[i]);
    }

    /* After iterating over the loop, the remaining 
elements in stack do not have the next greater 
element, so print -1 for them */
    while (s.empty() == false)
    {
        cout << s.top() << " --> " << -1 << endl;
        s.pop();
    }
}

vector<long long> nextLargerElement(long long arr[], int n)
{
    stack<int> stk;
    stk.push(0);
    vector<long long> ans(n, -1);

    for (int i = 1; i < n; i++)
    {
        while (!stk.empty() && arr[stk.top()] < arr[i])
        {
            ans[stk.top()] = arr[i];
            stk.pop();
        }
        stk.push(i);
    }

    return ans;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        vector<long long> res = nextLargerElement(arr, n);
        for (long long i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends