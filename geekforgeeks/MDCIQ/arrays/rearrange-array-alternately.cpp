#include <bits/stdc++.h>

using namespace std;

void rotateArray(int arr[], int n, int i)
{
    if (n == 0 || n == 1)
    {
        return;
    }
    int last = arr[n - 1];
    int m = n - 2;
    while (m >= i)
    {
        arr[m + 1] = arr[m];
        m--;
    }
    arr[i] = last;
}

void rearrangeArray(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        rotateArray(arr, n, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void rearrangeArray2(int arr[], int n)
{
    int j = n - 1;
    int i = 0;
    int k = 0;
    while (j >= i)
    {
        if (j == i)
        {
            cout << arr[j] << endl;
            break;
        }

        cout << arr[j] << " " << arr[i] << " ";
        j--;
        i++;
    }
}

void rearrangeArray3(int arr[], int n)
{
    // initialize index of first minimum and first
    // maximum element
    int max_idx = n - 1, min_idx = 0;

    // store maximum element of array
    int max_elem = arr[n - 1] + 1;

    // traverse array elements
    for (int i = 0; i < n; i++)
    {
        // at even index : we have to put maximum element
        if (i % 2 == 0)
        {
            arr[i] += (arr[max_idx] % max_elem) * max_elem;
            max_idx--;
        }

        // at odd index : we have to put minimum element
        else
        {
            arr[i] += (arr[min_idx] % max_elem) * max_elem;
            min_idx++;
        }
    }

    // array elements back to it's original form
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / max_elem;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    freopen("_input.txt", "r", stdin);
    int t = 0;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (size_t i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        rearrangeArray3(arr, N);
    }
    return 0;
}

/*
1
6
1 2 3 4 5 6
*/