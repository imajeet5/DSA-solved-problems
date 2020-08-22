
using namespace std;
#include <bits/stdc++.h>

int multiply(int x, int a[], int res_size)
{
    int carry = 0;

    for (int i = 0; i < res_size; i++)
    {
        int prod = a[i] * x + carry;
        a[i] = prod % 10;
        carry = prod / 10;
    }

    while (carry)
    {
        a[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

int main()
{
    int *a = new int[10000];

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        a[0] = 1;
        int siz = 1;
        for (int x = 2; x <= n; x++)
            siz = multiply(x, a, siz);

        for (int i = siz - 1; i >= 0; i--)
            cout << a[i];

        cout << endl;
    }
    delete (a);
    return 0;
}
