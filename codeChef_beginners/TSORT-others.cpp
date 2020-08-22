//Turbo Sort
// not working due to time Complexity

#include <bits/stdc++.h>

using namespace std;

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

    sort(arr, arr + T);

    for (int i = 0; i < T; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
