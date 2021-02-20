// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++)
            cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}
// } Driver Code Ends

/*You are required to complete this function*/

int maxLen(int A[], int n)
{
    int count = 0;
    unordered_map<int, int> mp;
    int i = -1;
    int sum = 0;
    mp[sum]++;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        // if already exists
        if (mp[sum] != 0)
        {
            count += mp[sum];
        }
        mp[sum]++;
    }

    return count;
}


/* 
1
6
0 0 5 5 0 0  
*/