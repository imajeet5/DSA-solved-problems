#include <bits/stdc++.h>

using namespace std;

void printSubSeq(int i, vector<int> &subseq, int arr[], int n)
{
    if (i == n)
    {
        for (auto el : subseq)
        {
            cout << el << " ";
        }
        if (subseq.size() == 0)
        {
            cout << "{}" << endl;
        }

        cout << endl;
        return;
    }
    // take the current index into the subsequence
    subseq.push_back(arr[i]);
    // move further by picking the current element
    printSubSeq(i + 1, subseq, arr, n);
    // do not pick the current element
    subseq.pop_back();
    // move further without taking the current element in the subsequence
    printSubSeq(i + 1, subseq, arr, n);
}

int main()
{

    int arr[] = {3, 2, 1};
    int n = 3;
    vector<int> subseq;
    printSubSeq(0, subseq, arr, n);
}