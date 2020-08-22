//Turbo Sort
// not working due to time Complexity

#include <bits/stdc++.h>

using namespace std;

void selection_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
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

    selection_sort(arr, T);
    for (int i = 0; i < T; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}

