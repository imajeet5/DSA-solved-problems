

#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

string largestTimeFromDigits(vector<int> &A)
{
    sort(begin(A), end(A), greater<int>());
    do
        if ((A[0] < 2 || (A[0] == 2 && A[1] < 4)) && A[2] < 6)
            return to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
    while (prev_permutation(begin(A), end(A)));
    return "";
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        vector<int> A(4);
        for (int i = 0; i < 4; i++)
        {
            cin >> A.at(i);
        }
        string result = largestTimeFromDigits(A);
        cout << result << endl;
    }
    return 0;
}