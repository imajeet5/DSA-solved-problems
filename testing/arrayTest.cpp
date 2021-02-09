#include <bits/stdc++.h>

using namespace std;




void changeArray(int arr[], int  n) {
    for (int i = 0; i < n; i++) {
        arr[i] += 1;
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const* argv[]) {
    int arr[5] = { 0 };
    changeArray(arr, 5);
    changeArray(arr, 5);
    changeArray(arr, 5);
    changeArray(arr, 5);
    printArr(arr, 5);
    return 0;
}