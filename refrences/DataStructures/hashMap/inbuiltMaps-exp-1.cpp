#include <bits/stdc++.h>

using namespace std;

vector<int> removeDuplicated(int *arr, int n)
{
    vector<int> result;
    unordered_map<int, bool> isPresent;

    for (int i = 0; i < n; i++)
    {
        if (!isPresent.count(arr[i]))
        {
            result.push_back(arr[i]);
            isPresent[arr[i]] = true;
        }
    }

    return result;
}

int main(int argc, char const *argv[])
{
    int a[] = {1, 5, 2, 4, 4, 3, 3, 6, 7, 1, 1, 2};
    vector<int> result = removeDuplicated(a, 12);
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result.at(i) << " ";
    }
    cout << endl;

    return 0;
}