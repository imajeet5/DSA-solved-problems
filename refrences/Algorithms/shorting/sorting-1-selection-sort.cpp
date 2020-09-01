// Selection sort

#include <bits/stdc++.h>

using namespace std;

int counter = 0;

void selection_sort(int *arr, int size)
{
    for (int i = 0; i <= size - 1; i++)
        for (int j = size - 1; j > i; j--)
        {
            counter++;
            if (arr[j] < arr[i])
                swap(arr[i], arr[j]);
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

    selection_sort(arr, T);
    for (int i = 0; i < T; i++)
    {
        cout << arr[i] << endl;
    }

    cout << "Total iterations: " << counter << endl;
    return 0;
}
