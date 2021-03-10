// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

void sortA1ByA2(int a1[], int n, int a2[], int m);

// Driver program to test above function
int main(int argc, char *argv[])
{

    int t;

    cin >> t;

    while (t--)
    {

        int n, m;
        cin >> n >> m;

        int a1[n];
        int a2[m];

        for (int i = 0; i < n; i++)
        {
            cin >> a1[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> a2[i];
        }

        sortA1ByA2(a1, n, a2, m);

        for (int i = 0; i < n; i++)
            cout << a1[i] << " ";

        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

//User function template in C++

// A1[] : the input array-1
// N : size of the array A1[]
// A2[] : the input array-2
// M : size of the array A2[]

int binarySearch(int arr[], int low, int high, int x, int n)
{

    // Checking condition
    if (high >= low)
    {

        // FInd the mid element
        int mid = low + (high - low) / 2;

        // Check if the element is the extreme left
        // in the left half of the array
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;

        // If the element lies on the right half
        if (x > arr[mid])
            return binarySearch(arr, (mid + 1), high, x, n);

        // Check for element in the left half
        return binarySearch(arr, low, (mid - 1), x, n);
    }

    // ELement not found
    return -1;
}
void sortA1ByA2(int A1[], int N, int A2[], int M)
{
    int temp[N], visited[N];
    // copy the elements of A1 to temp
    for (int i = 0; i < N; i++)
    {
        temp[i] = A1[i];
        visited[i] = 0;
    }

    // sorting the temp array
    sort(temp, temp + N);

    int ind = 0;

    for (int i = 0; i < M; i++)
    {
        int index = binarySearch(temp, 0, N - 1, A2[i], N);
        if (index == -1)
        {
            continue;
        }

        int j = index;
        //take all element that going forward are equal
        while (j < N && temp[j] == A2[i])
        {
            A1[ind++] = temp[j];
            visited[j] = 1;
            j++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0)
            A1[ind++] = temp[i];
    }
}