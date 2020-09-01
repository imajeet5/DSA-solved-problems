// it is based on recusrion - on divide and conqure technique.

#include <bits/stdc++.h>

using namespace std;

int counter = 0;

void mergeArrays(int x[], int y[], int a[], int s, int e)
{
    int mid = (s + e) / 2;
    int i = s;
    int j = mid + 1;
    int k = s;
    while (i <= mid && j <= e)
    {
        if (x[i] < y[j])
        {
            a[k] = x[i];
            i++;
            k++;
        }
        else
        {
            a[k] = y[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        a[k] = x[i];
        k++;
        i++;
    }
    while (j <= e)
    {
        a[k] = y[j];
        k++;
        j++;
    }
}

void mergeSort(int *arr, int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    int x[100], y[100];

    for (size_t i = 0; i <= mid; i++)
    {
        x[i] = arr[i];
    }
    for (int i = mid + 1; i <= e; i++)
    {
        y[i] = arr[i];
    }
    // this will sort the array x
    mergeSort(x, s, mid);
    // this will sort the array y
    mergeSort(y, mid + 1, e);
    // this will merge the sorted array x and y
    mergeArrays(x, y, arr, s, e);
}

int main(int argc, char const *argv[])
{
    int T = 0;
    cin >> T;
    int arr[T];
    int *sorted_arr;
    for (int i = 0; i < T; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, T - 1);
    for (int i = 0; i < T; i++)
    {
        cout << arr[i] << " ";
    }
    // cout << "Total iterations: " << counter << endl;

    return 0;
}
