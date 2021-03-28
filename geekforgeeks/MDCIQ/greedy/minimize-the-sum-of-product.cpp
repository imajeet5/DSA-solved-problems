// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long int minValue(int a[], int b[], int n);

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n], b[n];
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < n; i++)
            cin >> b[i];

        cout << minValue(a, b, n) << endl;
    }

    return 0;
} // } Driver Code Ends

long long int minValue(int a[], int b[], int n)
{
    // Your code goes here
    sort(a, a + n);
    sort(b, b + n);

    long long int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += a[i] * b[n - i - 1];
    }

    return result;
}