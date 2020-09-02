#include <bits/stdc++.h>
#define REP(i, a, n) for (i = a; i < n; i++)
//#define rep(i, n) REP(i, 0, n)

using namespace std;

typedef long long int ll;

void fix(int A[], int len)
{
    vector<int> values;
    for (int i = 0; i < len; i++)
    {
        if (A[i] != -1)
        {
            values.push_back(A[i]);
        }

        A[i] = -1;
    }

    for (auto v : values)
    {
        A[v] = v;
    }
}

int main()
{
    int A[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
              11, 10, 9, 5, 13, 16, 2, 14, 17, 4};

    int len = sizeof(A) / sizeof(A[0]);
    fix(A, len);

    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
    cout << endl;
}