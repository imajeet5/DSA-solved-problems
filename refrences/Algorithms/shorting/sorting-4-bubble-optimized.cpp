

#include <bits/stdc++.h>

using namespace std;

int counter = 0;

void bubble_sort(int *arr, int size)
{
    for (int i = size - 1; i >= 0; i--)
    {
        // assuming array is sorted at the beginning
        bool isArraySorted = true;
        for (int j = 0; j <= i - 1; j++)
        {
            counter++;
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                isArraySorted = false;
            }
        }
        if (isArraySorted)
        {
            break;
        }
    }
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

    bubble_sort(arr, T);
    for (int i = 0; i < T; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Total iterations: " << counter << endl;

    return 0;
}
