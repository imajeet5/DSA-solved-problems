#include <bits/stdc++.h>

using namespace std;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

vector<int> slicing(vector<int> &arr, int X, int Y)
{
    auto start = arr.begin() + X;
    auto end = arr.begin() + Y + 1;

    vector<int> result(Y - X + 1);

    copy(start, end, result.begin());

    return result;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 3, 4, 2, 4, 2, 1};
    //Range
    int X = 2, Y = 5;
    vector<int> result;
    result = slicing(arr, X, Y);
    printVec(result);
    return 0;
}

