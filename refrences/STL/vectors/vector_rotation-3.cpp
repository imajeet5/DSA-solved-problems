#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

void printVec(std::vector<int> const &a)
{

    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int r = 10;
    cin >> r;
    r %= arr.size();

    reverse(arr.begin(), arr.begin() + r);
    reverse(arr.begin() + r, arr.end());
    reverse(arr.begin(), arr.end());
    printVec(arr);

    return 0;
}