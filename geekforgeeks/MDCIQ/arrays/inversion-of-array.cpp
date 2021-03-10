#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int mergeArrays(int arr[], int temp[], int left, int mid, int right);
int mergeSort(int arr[], int temp[], int left, int right);

int countInversions(int arr[], int n)
{
    int inv = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j] && i < j)
            {
                inv++;
            }
        }
    }
    return inv;
}

int countInversions2(int arr[], int n)
{
    int temp[n];
    return mergeSort(arr, temp, 0, n - 1);
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv = 0;
    if (left >= right)
    {
        return inv;
    }
    mid = (left + right) / 2;
    inv += mergeSort(arr, temp, left, mid);
    inv += mergeSort(arr, temp, mid + 1, right);

    inv += mergeArrays(arr, temp, left, mid + 1, right);

    return inv;
}

int mergeArrays(int arr[], int temp[], int left, int mid, int right)
{
    // so we take three pointer as input, for array1, left is starting and mid - 1 is end.
    // for array2, mid is the starting and last is the end
    int i, j, k;
    int inv = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= (mid - 1)) && j <= right)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
            inv += mid - i;
        }
    }

    while (i <= mid - 1)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= right)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv;
}

int main(int argc, char const *argv[])
{
    // freopen("_input.txt", "r", stdin);

    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    cout << countInversions2(arr, n) << endl;

    return 0;
}

/*
1
5
2 4 1 3 5
*/