//Second Largest - other solutions

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {

        int a[3];

        for (int j = 0; j < 3; j++)
        {
            cin >> a[j];
        }

        sort(a, a + 3);
        cout << a[1] << "\n";
    }
    return 0;
}