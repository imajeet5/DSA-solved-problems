#include <bits/stdc++.h>

using namespace std;

bool isPresent(vector<int> &A, int x, int i)
{
    if (i == A.size())
    {
        return false;
    }

    if (A[i] == x)
    {
        return true;
    }

    return isPresent(A, x, i + 1);
}

int main(int argc, char const *argv[])
{
    // int arr[] = {2, 3, 4, 5, 9};
    vector<int> arr = {2, 3, 4, 5, 6, 9};
    int el = 0;
    cout << "Enter element to be searched" << endl;
    cin >> el;
    string result = isPresent(arr, el, 0) ? "true" : "false";

    cout << "Is Present " << result << endl;

    return 0;
}